import scala.util.parsing.combinator.JavaTokenParsers

case class Ptr      (isConst: Boolean)

case class Type(name: String, isConst: Boolean, ptrs: List[Ptr]) {
    private def constStr(const: Boolean) = if (const) " const" else ""
    override val toString = (name :: constStr(isConst) :: ptrs.map {
        case Ptr(ptrIsConst) => "*" + constStr(ptrIsConst)
    }).mkString("")
}

case class Arg(name: String, argType: Type, annotation: Option[Annotation], arraySize: Option[Int]) {
    override val toString = argType.toString + " " + name + (arraySize match {
        case None => ""
        case Some(n) => "[" + n.toString + "]"
    })
}
case class Method(name: String, retType: Type, args: List[Arg]) {
    override val toString = retType + name + "(" + args.mkString(", ") + ")"
}
case class Interface(name: String, parentName: String, methods: List[Method])
case class Annotation(name: String, expr: Option[String])


object ParserImpl {
    case class AnnotationType(name: String)
}

class ParserImpl extends JavaTokenParsers with InterfaceParser {
    import ParserImpl._

    def interfaces : Parser[List[Interface]] = rep(interface)
    def interface  : Parser[Interface   ] = midl ~> ident ~ parent ~ ("{" ~> body <~ "}") ^^
        { case name ~ parentName ~ methods => Interface(name, parentName, methods)}

    def parent     : Parser[String      ] = ":" ~> "public" ~> ident
    def midl       : Parser[String      ] = "MIDL_INTERFACE" ~> "(" ~> stringLiteral <~ ")"

    def body       : Parser[List[Method]] = rep(publicBlock) ^^ { _.flatten }
    def publicBlock: Parser[List[Method]] = "public" ~> ":" ~> rep(method)
    def method     : Parser[Method      ] =  ("virtual" ~> argType) ~ ("STDMETHODCALLTYPE" ~> ident) ~ ("(" ~> args <~ ")") <~ "=" <~ "0" <~ ";" ^^
        { case retType ~ name ~ args => Method(name, retType, args) }

    def args       : Parser[List[Arg]   ] = noArgs | hasArgs
    def noArgs     : Parser[List[Arg]   ] = "void" ^^ { _ => List() }
    def hasArgs    : Parser[List[Arg]   ] = repsep(arg, ",")

    def arg        : Parser[Arg         ] = (annotation?) ~ argType ~ ident ~ (("[" ~> decimalNumber <~ "]")?) ^^
        { case annotation ~ argType ~ name ~ arraySize  => Arg(name
            , argType
            , annotation
            , arraySize map (_.toInt)) }

    def argType    : Parser[Type        ] = argTypeCore ~ rep(argTypePtr) ^^ { case Type(name, isConst, List()) ~ ptrs => Type(name, isConst, ptrs) }
    def argTypeCore: Parser[Type        ] = const ~ ident ~ const ^^ { case c1 ~ name ~ c2 => Type(name, c1 || c2, List()) }
    def argTypePtr : Parser[Ptr         ] = "*" ~> const ^^ { isConst => Ptr(isConst)}
    def const      : Parser[Boolean     ] = ("const"?) ^^ { case o => !o.isEmpty }

    def annotation : Parser[Annotation] = annotationType ~ (("(" ~> annotationExpr <~ ")")?) ^^
        { case AnnotationType(name) ~ expr => Annotation(name, expr) }

//    def annotationType: Parser[AnnotationType] = annotationTypeInout | annotationTypeIn | annotationTypeOut
//    def annotationTypeInout = "(__inout[a-z_]*)".r ^^ { case name => AnnotationType(name, isIn = true , isOut = true ) }
//    def annotationTypeIn    = "(__in[a-z_]*)"   .r ^^ { case name => AnnotationType(name, isIn = true , isOut = false) }
//    def annotationTypeOut   = "(__out[a-z_]*)"  .r ^^ { case name => AnnotationType(name, isIn = false, isOut = true ) }

    def annotationType : Parser[AnnotationType] = "_([A-Za-z_]+)_".r ^^ { case a => AnnotationType(a) }

    def annotationExpr: Parser[String] = annotationExprInexpr | annotationExprInner

    def annotationExprInexpr: Parser[String] = "_Inexpressible_" ~> ("(" ~> annotationExprInner <~ ")")
    def annotationExprInner: Parser[String] = "[^\\)]*".r

    case class ParseException(msg: String) extends RuntimeException(msg)

    def parse(text: String): List[Interface] = {
        val res = parseAll(interfaces, text)

        if (!res.successful)
            throw new ParseException(res.toString)

        res.get
    }

    def parse1(text: String): Interface = {
        val res = parseAll(interface, text)

        if (!res.successful)
            throw new ParseException(res.toString)

        res.get
    }
}
