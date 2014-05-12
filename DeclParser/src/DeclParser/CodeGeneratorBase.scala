package DeclParser

import BaseTypes._

abstract class CodeGeneratorBase(head: String, namespaces: List[String]) extends CodeGenerator {
    def process(interfaces: Interfaces) : String = {
        val sb = new StringBuilder

        sb ++= head

        sb ++= openNamespaces(namespaces)

        interfaces.foreach((interface) => {
            sb ++= processInterface(interface)
        })

        sb ++= closeNamespaces(namespaces)

        sb.toString()
    }

    private def openNamespaces(namespaces: List[String]) : String = {
        namespaces.map(
            (ns) => "namespace " + ns + "\r\n{\r\n"
        ).mkString("")
    }

    private def closeNamespaces(namespaces: List[String]) : String = {
        namespaces.map(
            (ns) => "} // namespace " + ns + "\r\n\r\n"
        ).mkString("")
    }

    private def processInterface(interface: Interface) : String = {
        def methodText(m0: StdMethod) : String = {
            val m = fixUnnamedArgs(m0)

            val argsString = m.args.map((arg) => arg.argType + (arg.name match {
                case Some(name) => " " + name
            })).mkString(", ")

            val body = methodBody(interface, m)

            """%s %s::%s(%s)
              |{
              |%s
              |}
              |
              |""".stripMargin.format(m.retType, interfaceName(interface), m.name, argsString, body)
        }

        val sb = new StringBuilder

        sb ++= interfaceHead(interface)

        interface.methods.foreach((m) => {
            sb ++= methodText(m)
        })

        sb.toString()
    }

    private def fixUnnamedArgs(args: Args) : Args = {
        var counter: Int = 0

        def newName(): String = {
            val res = "unnamed" + counter.toString
            counter += 1
            res
        }

        args.map(
            (arg) => Arg(arg.argType, arg.name match {
                case Some(s) => Some(s)
                case None => Some(newName())
            })
        )
    }

    private def fixUnnamedArgs(m: StdMethod) : StdMethod = {
        StdMethodRet(m.name, m.retType, fixUnnamedArgs(m.args))
    }

    def interfaceName(interface: Interface) : String
    def interfaceHead(interface: Interface) : String
    def methodBody(interface: Interface, method: StdMethod) : String
}
