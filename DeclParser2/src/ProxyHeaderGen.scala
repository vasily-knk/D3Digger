class ProxyHeaderGen extends CodeGenerator {
    override def generate(interfaces: List[Interface]): String = {
        val header =
            """
              |template<typename T>
              |struct IProxy<T>;
            """.stripMargin

        def writeArgs(args: List[Arg]): String = args.map {
            case Arg(name, argType, annotation, arraySize) => argType.toString + " " + name + (arraySize match {
                case None => ""
                case Some(num) => "[" + num.toString + "]"
            })
        }.mkString(", ")

        def writeMethods(i: Interface): String = {
            i.methods.map {
                case Method(name, retType, args) => "    " + retType.toString + " " + name + "(" + writeArgs(args) + ") override = 0;"
            }.mkString("\r\n")
        }

        val strings = interfaces.map { interface =>
            """
              |template<>
              |struct IProxy<%s>
              |    : %s
              |    , IProxy<%s>
              |{
              |%s
              |};
            """.stripMargin.format(interface.name, interface.name, interface.parentName, writeMethods(interface))
        }

        (header :: strings).mkString("\r\n")
    }
}
