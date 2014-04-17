package DeclParser

object BaseTypes {
    case class Arg(argType: String, name: Option[String])
    type Args = List[Arg]

    trait StdMethod {
        def name: String
        def retType: String
        def args: Args
    }

    type StdMethods = List[StdMethod]

    case class Interface(name: String, methods: StdMethods)
    type Interfaces = List[Interface]
}
