package DeclParser

import BaseTypes._

object CodeGenerator {
    def stripName(name: String) = {
        class BadNameException extends RuntimeException

        val pattern = """IDirect3D(\w*)9""".r

        val stripped = name match {
            case pattern(str) => str
            case _ => throw new BadNameException()
        }

        if (stripped.isEmpty) "D3D" else stripped
    }

    val baseNamespaces = List("D3Digger", "D3D9")
    private def proxyFilename(name: String) = "gen/d3d9/" + name

    private type PW = java.io.PrintWriter

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

}

class CodeGenerator extends InterfacesProcessor {
    import CodeGenerator._


    private def writeHeader(i: Interface) {
        val name = stripName(i.name)
        val namespaces = baseNamespaces :+ name
        val pw = new PW(proxyFilename(name) + ".h")

        pw.println("#pragma once")
        pw.println()


        pw.println(openNamespaces(namespaces))

        pw.println(
            """typedef %s IBase;
              |typedef %s *IBasePtr;
            """.stripMargin.format(i.name, i.name))

        pw.println(
            """struct ProxyBase
              |    : IBase
              |{
              |    ProxyBase(IBasePtr pimpl);
            """.stripMargin)


        i.methods.foreach((m) => {
            pw.print("    ")
            pw.print(m.retType + " STDMETHODCALLTYPE " + m.name + "(")

            val argStrings = m.args.map((arg) => arg.argType + (arg.name match {
                case Some(name) => " " + name
                case None => ""
            }))

            pw.print(argStrings.mkString(", "))
            pw.println(") override;")
        })


        pw.println(
            """
              |private:
              |    IBasePtr pimpl_;
              |};
            """.stripMargin)

        pw.println("typedef ProxyBase *ProxyBasePtr;")
        pw.println(closeNamespaces(namespaces))
        pw.close()
    }

    private def writeCPP(i: Interface) {
        val name = stripName(i.name)
        val namespaces = baseNamespaces :+ name
        val pw = new PW(proxyFilename(name) + ".cpp")

        val headerName = name + ".h"
        pw.println("#include \"%s\"".format(headerName))
        pw.println()

        pw.println(openNamespaces(namespaces))

        pw.println("ProxyBase::ProxyBase(IBasePtr pimpl)")
        pw.println("    : pimpl_(pimpl)")
        pw.println("{")
        pw.println("}")
        pw.println()

        i.methods.foreach((m) => {
            val args = fixUnnamedArgs(m.args)

            pw.print(m.retType + " " + "ProxyBase::" + m.name + "(")

            val argStrings = args.map((arg) => arg.argType + (arg.name match {
                case Some(name) => " " + name
            }))

            pw.print(argStrings.mkString(", "))
            pw.println(")")
            pw.println("{")

            pw.print("    ")
            if (m.retType != "void")
                pw.print("return ")

            pw.print("pimpl_->" + m.name + "(")
            val argStringsOnlyNames = args.map((arg) => arg.name match {
                case Some(name) => name
            })

            pw.print(argStringsOnlyNames.mkString(", "))
            pw.println(");")

            pw.println("}")
            pw.println()
        })


        pw.println(closeNamespaces(namespaces))

        pw.close()
    }

    private def processInterface(i: Interface) {
        writeHeader(i)
        writeCPP(i)
    }

    def process(interfaces: Interfaces) {
        interfaces.foreach(processInterface)
    }
}
