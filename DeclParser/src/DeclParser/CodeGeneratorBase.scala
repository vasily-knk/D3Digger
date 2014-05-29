package DeclParser

import BaseTypes._

abstract class CodeGeneratorBase(head: String, namespaces: List[String]) extends CodeGenerator {
    final def process(interfaces: Interfaces) : String = {
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
        def methodText(m: StdMethod) : String = {
            val argsString = methodArgs(interface, m)
            val unshiftedBody = methodBody(interface, m)

            val bodyLines = unshiftedBody.split("\\r?\\n").map((line) => "    " + line)
            val body = bodyLines.mkString("\r\n")

            val ret = methodRet(interface, m)

            """%s %s::%s(%s)
              |{
              |%s
              |}
              |
              |""".stripMargin.format(ret, interfaceName(interface), m.name, argsString, body)
        }

        val sb = new StringBuilder

        sb ++= interfaceHead(interface)

        interface.methods.foreach((m) => {
            sb ++= methodText(m)
        })

        sb.toString()
    }

    def methodArgs(interface: Interface, method: StdMethod) : String = {
        method.args.map((arg) => arg.argType + " " + arg.name).mkString(", ")
    }

    def methodRet(interface: Interface, method: StdMethod) : String = {
        method.retType.toString
    }

    def interfaceName(interface: Interface) : String
    def interfaceHead(interface: Interface) : String
    def methodBody(interface: Interface, method: StdMethod) : String
}
