package DeclParser

object BaseTypes {
    case class ArgType(name: String, isConst: Boolean, ptrDepth: Int, isIn: Boolean) {
        override val toString: String = (if (isConst) "const " else "") + name + "*" * ptrDepth
    }
    case class Arg(argType: ArgType, name: Option[String]) {
        override val toString: String = argType + " " + name.getOrElse("")
    }
    type Args = List[Arg]

    trait StdMethod {
        def name: String
        def retType: ArgType
        def args: Args
    }

    case class StdMethodRet(override val name: String, override val retType: ArgType, override val args: Args) extends StdMethod

    type StdMethods = List[StdMethod]

    case class Interface(name: String, methods: StdMethods)
    type Interfaces = List[Interface]
}
