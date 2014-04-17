import scala.util.parsing.combinator._
import scala.collection.immutable._

object MyLang {
    trait Value extends Expr {
        def integer: Int = throw new WrongType("integer")
        def real: Double = throw new WrongType("real")
        def literal: String = throw new WrongType("literal")
        def bool: Boolean = throw new WrongType("boolean")

        def field(name : String) : Value = throw new WrongField(name)

        override def eval(context: Context) = this

        case class WrongType(smth:String) extends Exception
        case class WrongField(smth:String) extends Exception
    }

    type Args = List[String]
    type CallArgs = List[Expr]
    type ArgValues = List[Value]

    case class IntValue(override val integer: Int) extends Value {
        def this(b : Boolean) = this(if (b) 1 else 0)

        override def bool = integer != 0
    }

    case class DoubleValue(override val real: Double) extends Value {
        override def bool = real != 0
    }
    case class LitValue(override val literal: String) extends Value

    type Vars = Map[String, Value]
    type Funcs = Map[String, FuncBase]

    case class Context(vars: Vars, funcs: Funcs)

    trait Expr {
        class RValueAssignment extends Exception {
            override val toString = "Can't assign an RValue"
        }
        def eval(context: Context) : Value
        def assign(context: Context, value: Expr) : Context = throw new RValueAssignment
    }

    case class FieldExpr(left : Expr, field : String) extends Expr {
        def eval(context: Context): Value = {
            left.eval(context).field(field)
        }
    }

    case class BinaryExpression(left: Expr, op: String, right: Expr) extends Expr {
        def eval(context: Context) : Value = {
            val values = (left.eval(context), right.eval(context))

            values match {
                case (LitValue(s1), LitValue(s2)) =>
                    op match {
                        case "+" => LitValue(s1 + s2)
                    }
                case (DoubleValue(leftVal), DoubleValue(rightVal)) =>
                    op match {
                        case "+" => DoubleValue(leftVal + rightVal)
                        case "-" => DoubleValue(leftVal - rightVal)
                        case "*" => DoubleValue(leftVal * rightVal)
                        case "/" => DoubleValue(leftVal / rightVal)

                        case "<" => new IntValue(leftVal < rightVal)
                        case ">" => new IntValue(leftVal > rightVal)
                        case "<=" => new IntValue(leftVal <= rightVal)
                        case ">=" => new IntValue(leftVal >= rightVal)

                        case "==" => new IntValue(leftVal == rightVal)
                        case "!=" => new IntValue(leftVal != rightVal)
                    }
                case (IntValue(leftVal), IntValue(rightVal)) =>
                    op match {
                        case "+" => IntValue(leftVal + rightVal)
                        case "-" => IntValue(leftVal - rightVal)
                        case "*" => IntValue(leftVal * rightVal)
                        case "/" => IntValue(leftVal / rightVal)

                        case "<" => new IntValue(leftVal < rightVal)
                        case ">" => new IntValue(leftVal > rightVal)
                        case "<=" => new IntValue(leftVal <= rightVal)
                        case ">=" => new IntValue(leftVal >= rightVal)

                        case "==" => new IntValue(leftVal == rightVal)
                        case "!=" => new IntValue(leftVal != rightVal)

                        case "&&" => new IntValue(leftVal != 0 && rightVal != 0)
                        case "||" => new IntValue(leftVal != 0 || rightVal != 0)
                    }
            }
        }
    }

    case class NumericExpr(number: Double) extends Expr {
        override def eval(context: Context): Value = DoubleValue(number)
    }

    case class LiteralExpression(string: String) extends Expr {
        override def eval(context: Context): Value = LitValue(string.substring(1, string.length - 1))
    }

    case class ParenthesisedExpression(expr: Expr) extends Expr {
        override  def eval(context: Context): Value = expr.eval(context)
    }

    case class VariableExpression(name: String) extends Expr {
        case class VarNotFound(smth:String) extends Exception

        def eval(context: Context): Value = {
            if (!context.vars.contains(name))
                throw VarNotFound("Variable not found: " + name)
            else
                context.vars.get(name).get
        }
    }

    case class Body(assignments: List[Assignment], expr: Expr) extends Expr {
        def eval(context: Context): Value = {
            var newContext = context
            assignments.map({
                case Assignment(name, e) => newContext = Context(newContext.vars + (name -> e.eval(newContext)), newContext.funcs)
            })

            expr.eval(newContext)
        }
    }

    trait FuncBase {
        class WrongArgsNum extends Exception {
            override val toString = "Wrong number of args"
        }

        def name : String
        def call(argValues: ArgValues, funcs: Funcs) : Value
    }

    case class StructValue(vars : Vars) extends Value {
        override def field(name : String) : Value =  vars.get(name) match {
            case Some(value) => value
            case None => throw new WrongField(name)
        }
    }

    case class StructFunc(name: String, args: Args) extends FuncBase {
        override def call(argValues: ArgValues, funcs: Funcs) : Value = {
            if (argValues.length != args.length)
                throw new WrongArgsNum

            var vars = new HashMap[String, Value]
            for ((argName, argValue) <- args zip argValues)
                vars += (argName -> argValue)

            StructValue(vars)
        }
    }

    case class UserFunc(name: String, args: Args, body: Body) extends FuncBase {
        override def call(argValues: ArgValues, funcs: Funcs) : Value = {
            if (argValues.length != args.length)
                throw new WrongArgsNum

            var vars = new HashMap[String, Value]
            for ((argName, argValue) <- args zip argValues)
                vars += (argName -> argValue)

            body.eval(Context(vars, funcs))
        }
    }

    case class Assignment(name: String, e: Expr)

    case class CallExpr(name: String, args: CallArgs) extends Expr {
        def eval(context: Context): Value = {
            val argValues = args.map((e: Expr) => e.eval(context))
            context.funcs.get(name).get.call(argValues, context.funcs)
        }
    }

    case class CondExpr(condition: Expr, thenBlock: Body, elseBlock: Body) extends Expr {
        override def eval(context: Context): Value =
            if (condition.eval(context).bool)
                thenBlock.eval(context)
            else
                elseBlock.eval(context)
    }

    object Prog {
        def list2map(list: List[FuncBase]): Funcs = {
            var funcs = new HashMap[String, FuncBase]
            list.map({
                case f => funcs += (f.name -> f)
            })
            funcs
        }
    }

    class Prog(userFuncs: Funcs) {
        private val funcs = userFuncs + ("double2int" -> Double2Int) + ("int2double" -> Int2Double)

        def this(list: List[FuncBase]) = {
            this(Prog.list2map(list))
        }

        object Double2Int extends FuncBase {
            override val name = "double2int"
            def call(argValues: ArgValues, funcs: Funcs) : Value =
                if (argValues.size != 1)
                    throw new WrongArgsNum
                else
                    IntValue(argValues(0).real.toInt)
        }

        object Int2Double extends FuncBase {
            override val name = "int2double"
            def call(argValues: ArgValues, funcs: Funcs) : Value =
                if (argValues.size != 1)
                    throw new WrongArgsNum
                else
                    DoubleValue(argValues(0).integer.toDouble)
        }

        def run: Value = {
            funcs.get("main").get.call(List(), funcs)
        }
    }
}

class MyLang extends JavaTokenParsers {
    import MyLang._
    def convertToBinary: PartialFunction[ ~[Expr, List[ ~[String, Expr]]], Expr] = {
        case left ~ list =>
            if (list.isEmpty) left
                else list.foldLeft(left) {
                case (res, op ~ right) => BinaryExpression(res, op, right)
            }
    }

    def assign: Parser[Assignment] = (ident <~ "=") ~ expr ^^ { case name ~ e => Assignment(name, e) }
    def expr = logicalOr
    def logicalOr: Parser[Expr] = logicalAnd ~ rep("||" ~ logicalAnd) ^^ convertToBinary
    def logicalAnd: Parser[Expr] = comparison ~ rep("&&" ~ comparison) ^^ convertToBinary
    def comparison: Parser[Expr] = ordering ~ rep("==" ~ ordering | "!=" ~ ordering) ^^ convertToBinary
    def ordering: Parser[Expr] = additive ~ rep("<" ~ additive | ">" ~ additive | "<=" ~ additive | ">=" ~ additive) ^^ convertToBinary
    def additive: Parser[Expr] = multiplicative ~ rep("+" ~ multiplicative | "-" ~ multiplicative) ^^ convertToBinary
    def multiplicative: Parser[Expr] = reference ~ rep("*" ~ reference | "/" ~ reference) ^^ convertToBinary
    def reference: Parser[Expr] = factor ~ rep("." ~> ident) ^^ { case e ~ fields =>
        fields.foldLeft(e) {
            case (res, field) => FieldExpr(res, field)
        }
    }

    def callArgs: Parser[CallArgs] = "(" ~> repsep(expr, ",") <~ ")"

    def call: Parser[Expr] = ident ~ callArgs ^^ {case name ~ args => CallExpr(name, args)}

    def number: Parser[Expr] = floatingPointNumber ^^ { case s =>
        if ("""-?\d+""".r.pattern.matcher(s).matches())
            IntValue(s.toInt)
        else
            DoubleValue(s.toDouble)
    }

    def factor: Parser[Expr] =
        number |
        stringLiteral       ^^ LiteralExpression  |
        cond |
        call |
        ident               ^^ VariableExpression |
        ("(" ~> expr <~ ")")


    def body: Parser[Body] = (("{" ~> rep(assign <~ ";")) ~ expr <~ "}" ^^ { case list ~ e => Body(list, e) }) |
        expr ^^ { case e => Body(List(), e)}

    def then_block: Parser[Body] = "then" ~> body
    def else_block: Parser[Body] = "else" ~> body

    def cond: Parser[CondExpr] = ("if" ~> expr) ~ then_block ~ else_block ^^ { case cond ~ thenBlock ~ elseBlock => CondExpr(cond, thenBlock, elseBlock) }

    def args: Parser[Args] = "(" ~> repsep(ident, ",") <~ ")"

    def func: Parser[FuncBase] = ("def" ~> ident) ~ args ~ body ^^ {case name ~ args ~ body => UserFunc(name, args, body) }

    def structFields: Parser[Args] = "{" ~> repsep(ident, ",") <~ "}"

    def struct: Parser[FuncBase] = ("struct" ~> ident) ~ structFields ^^ {case name ~ args => StructFunc(name, args) }

    def prog: Parser[Prog] = rep(func | struct) ^^ { case list => new Prog(list) }
}

object Hello extends MyLang {
    def main(args: Array[String]) {



        val text = """
                     | struct Foo { whats, up }
                     | struct Bar { im, good }
                     |
                     | def sum(a, b) { c = a + b; c }
                     |
                     |
                     |
                     | def main() {
                     |   string = "Hello";
                     |   string = sum(string, " world");
                     |   foo = Foo(int2double(3), string);
                     |   if (1 < 0 && 1) then string else Bar(foo, ":)").im.whats
                     | }
                   """.stripMargin

        val res = parseAll(prog, text)

        if(res.successful)
            println(res.get.run)
        else
            println(res)

    }
}

