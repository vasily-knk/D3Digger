import scala.util.parsing.combinator.JavaTokenParsers

case class Ptr      (isConst: Boolean)
case class Type     (name: String, isConst: Boolean, ptrs: List[Ptr])
case class Arg      (name: String, argType: Type, annotation: Annotation, arraySize: Option[Int])
case class Method   (name: String, retType: Type, args: List[Arg])
case class Interface(name: String, parentName: String, methods: List[Method])
case class Annotation(name: String, comment: Option[String])


class ParserImpl extends JavaTokenParsers with InterfaceParser {
    def interfaces : Parser[List[Interface]] = rep(interface)
    def interface  : Parser[Interface   ] = midl ~> ident ~ parent ~ ("{" ~> body <~ "};") ^^ { case name ~ parentName ~ methods => Interface(name, parentName, methods)}

    def parent     : Parser[String      ] = ":" ~> "public" ~> ident
    def midl       : Parser[String      ] = "MIDL_INTERFACE" ~> "(" ~> stringLiteral <~ ")"

    def body       : Parser[List[Method]] = rep(publicBlock) ^^ { _.flatten }
    def publicBlock: Parser[List[Method]] = "public" ~> ":" ~> rep(method)
    def method     : Parser[Method      ] =  ("virtual" ~> argType) ~ ("STDMETHODCALLTYPE" ~> ident) ~ ("(" ~> args <~ ")") <~ "=" <~ "0" <~ ";" ^^
        { case retType ~ name ~ args => Method(name, retType, args) }

    def args       : Parser[List[Arg]   ] = noArgs | hasArgs
    def noArgs     : Parser[List[Arg]   ] = "void" ^^ { _ => List() }
    def hasArgs    : Parser[List[Arg]   ] = repsep(arg, ",")

    def arg        : Parser[Arg         ] = annotation ~ argType ~ ident ~ (("[" ~> decimalNumber <~ "]")?) ^^ { case annotation ~ argType ~ name ~ arraySize => Arg(name, argType, annotation, arraySize map (_.toInt)) }

    def argType    : Parser[Type        ] = argTypeCore ~ rep(argTypePtr) ^^ { case Type(name, isConst, List()) ~ ptrs => Type(name, isConst, ptrs) }
    def argTypeCore: Parser[Type        ] = const ~ ident ~ const ^^ { case c1 ~ name ~ c2 => Type(name, c1 || c2, List()) }
    def argTypePtr : Parser[Ptr         ] = "*" ~> const ^^ { isConst => Ptr(isConst)}
    def const      : Parser[Boolean     ] = ("const"?) ^^ { case o => !o.isEmpty }


    def annotation : Parser[Annotation] = annotationType ~ (("(" ~> annotationComment <~ ")")?) ^^ { case name ~ comment => Annotation(name, comment) }
    def annotationType: Parser[String] = "__([a-z_]+)".r
    def annotationComment: Parser[String] = "[^\\)]*".r

    case class ParseException(msg: String) extends RuntimeException(msg)

    def parse(text: String): List[Interface] = {
        val res = parseAll(interfaces, text)

        if (!res.successful)
            throw new ParseException(res.toString)

        res.get
    }
}
