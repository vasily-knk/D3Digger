import scala.util.parsing.combinator._

class DeclParser extends JavaTokenParsers {
    trait StdMethod {}
    case class Arg(argType: String, name: Option[String])
    type Args = List[Arg]

    def argType: Parser[String] = ident
    def arg: Parser[Arg] = argType ~ (ident?) ^^ { case t ~ name => Arg(t, name) }

    def emptyArgs: Parser[Args] = "THIS" ^^ { case str => Nil }
    def nonEmptyArgs: Parser[Args] = "THIS_" ~> repsep(arg, ",")
    def args: Parser[Args] = nonEmptyArgs | emptyArgs

    def brArgs: Parser[Args] = ("(" ~> args) <~ ")"
    //def stdmethod: Parser[StdMethod] = "STDMETHOD" ~> (("(" ~> ident) <~ ")")
}

object Main extends DeclParser {

    def main(argv: Array[String]) {
        //val text = "STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;"
         val text = "(THIS_ UINT StartRegister,float pConstantData,UINT Vector4fCount)"
        val res = parseAll(brArgs, text)

        if(res.successful)
            println(res.get)
        else
            println(res)
    }
}

