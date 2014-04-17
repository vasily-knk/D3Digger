import scala.util.parsing.combinator._

object DeclParser {
    case class Arg(argType: String, name: Option[String])
    type Args = List[Arg]

    trait StdMethod {
        def name: String
        def retType: String
        def args: Args
    }

    type StdMethods = List[StdMethod]

    case class StdMethodHR(override val name: String, override val args: Args) extends StdMethod {
        override val retType = "HRESULT"
    }

    case class StdMethodRet(override val name: String, override val retType: String, override val args: Args) extends StdMethod

    case class Interface(name: String, methods: StdMethods)
    type Interfaces = List[Interface]
}

class DeclParser extends JavaTokenParsers {
    import DeclParser._

    def stars: Parser[String] = rep("*") ^^ { case lst => lst.mkString("") }
    def constType: Parser[String] = ("CONST"?) ~ ident ^^ {
        case Some(const) ~ t => const + " " + t
        case None ~ t => t
    }

    def argType: Parser[String] = constType ~ stars ^^ { case t ~ s => t + s }
    def arg: Parser[Arg] = argType ~ (ident?) ^^ { case t ~ name => Arg(t, name) }

    def emptyArgs: Parser[Args] = "THIS" ^^ { case str => Nil }
    def nonEmptyArgs: Parser[Args] = "THIS_" ~> repsep(arg, ",")
    def args: Parser[Args] = nonEmptyArgs | emptyArgs

    def brArgs: Parser[Args] = "(" ~> args <~ ")"

    def stdMethodHR: Parser[StdMethodHR] = "STDMETHOD" ~> (("(" ~> ident <~ ")") ~ brArgs) <~ "PURE" ^^ {
        case name ~ args => StdMethodHR(name, args)
    }

    def stdMethodRet: Parser[StdMethodRet] = "STDMETHOD_" ~> ((("(" ~> argType <~ ",") ~ ident <~ ")") ~ brArgs) <~ "PURE" ^^ {
        case t ~ name ~ args => StdMethodRet(name, t, args)
    }

    def stdMethod: Parser[StdMethod] = stdMethodRet | stdMethodHR

    def interfaceDecl: Parser[String] = ("DECLARE_INTERFACE_" ~ "(") ~> ((ident <~ "," ) <~ ident) <~ ")"
    def interfaceBody: Parser[StdMethods] = rep(stdMethod <~ ";")
    def interface: Parser[Interface] = interfaceDecl ~ ("{" ~> interfaceBody <~ "}") ^^ {
        case name ~ methods => Interface(name, methods)
    }

    def interfaces: Parser[Interfaces] = rep (interface <~ ";")

}

object Main extends DeclParser {
    private def printMethods(methods: DeclParser.StdMethods) {
        methods.foreach {
            case m => println(m.retType, m.name, "(" + m.args.size + ")")
        }
    }

    private def printInterfaces(interfaces: DeclParser.Interfaces) {
        interfaces.foreach {
            case i => println(i.name, i.methods.size)
        }
    }

    def main(argv: Array[String]) {
        val text = scala.io.Source.fromFile("src.txt").mkString
        val res = parseAll(interfaces, text)

        if(res.successful)
            printInterfaces(res.get)
        else
            println(res)
    }
}

