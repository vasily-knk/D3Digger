package DeclParser

import BaseTypes._
import scala.util.parsing.combinator._

object ParserImpl {
    case class StdMethodHR(override val name: String, override val args: Args) extends StdMethod {
        override val retType = ArgType("HRESULT", false, 0, false)
    }
    case class StdMethodHRSync(override val name: String, override val args: Args) extends StdMethod {
        override val retType = ArgType("HRESULT_SYNC", false, 0, false)
    }
}

class ParserImpl extends  JavaTokenParsers with InterfacesParser{
    import ParserImpl._

    def stars: Parser[Int] = rep("*") ^^ { case lst => lst.size }

    def inType: Parser[Boolean] = ("_IN"?) ^^ {
      case Some(const) => true
      case None => false
    }

    def constType: Parser[Boolean] = ("CONST"?) ^^ {
        case Some(const) => true
        case None => false
    }

    def argType: Parser[ArgType] = inType ~ constType ~ ident ~ stars ^^ { case isIn ~ isConst ~ name ~ depth => ArgType(name, isConst, depth, isIn) }
    def arg: Parser[Arg] = argType ~ ident ^^ { case t ~ name => Arg(t, name) }

    def emptyArgs: Parser[Args] = "THIS" ^^ { case str => Nil }
    def nonEmptyArgs: Parser[Args] = "THIS_" ~> repsep(arg, ",")
    def args: Parser[Args] = nonEmptyArgs | emptyArgs

    def brArgs: Parser[Args] = "(" ~> args <~ ")"

    def stdMethodHR: Parser[StdMethodHR] = "STDMETHOD" ~> (("(" ~> ident <~ ")") ~ brArgs) <~ "PURE" ^^ {
        case name ~ args => StdMethodHR(name, args)
    }

    def stdMethodHRSync: Parser[StdMethodHRSync] = "STDMETHOD_SYNC" ~> (("(" ~> ident <~ ")") ~ brArgs) <~ "PURE" ^^ {
        case name ~ args => StdMethodHRSync(name, args)
    }

    def stdMethodRet: Parser[StdMethodRet] = "STDMETHOD_" ~> ((("(" ~> argType <~ ",") ~ ident <~ ")") ~ brArgs) <~ "PURE" ^^ {
        case t ~ name ~ args => StdMethodRet(name, t, args)
    }

    def stdMethod: Parser[StdMethod] = stdMethodHRSync | stdMethodRet | stdMethodHR

    def interfaceDecl: Parser[String] = ("DECLARE_INTERFACE_" ~ "(") ~> ((ident <~ "," ) <~ ident) <~ ")"
    def interfaceBody: Parser[StdMethods] = rep(stdMethod <~ ";")
    def interface: Parser[Interface] = interfaceDecl ~ ("{" ~> interfaceBody <~ "}") ^^ {
        case name ~ methods => Interface(name, methods)
    }

    def interfaces: Parser[Interfaces] = rep (interface <~ ";")

    def parse(text: String): Interfaces = {
        val res = parseAll(interfaces, text)

        if (!res.successful)
            throw new ParseException(res.toString)

        res.get
    }
}
