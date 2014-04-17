import scala.util.parsing.combinator._

/*

class DeclParser extends JavaTokenParsers {
}

object Main extends DeclParser {
    private def printMethods(methods: DeclParser.DeclParser.StdMethods) {
        methods.foreach {
            case m => println(m.retType, m.name, "(" + m.args.size + ")")
        }
    }

    private def printInterfaces(interfaces: DeclParser.DeclParser.Interfaces) {
        def saveInterface(interface: DeclParser.DeclParser.Interface) {
            def stripName(interfaceName: String) {

            }

            def proxyFilename(interfaceName: String) = "gen/" + interfaceName + "Proxy"
            type PW = java.io.PrintWriter

            def saveH(interface: DeclParser.DeclParser.Interface) {
                val pw = new PW(proxyFilename(interface.name) + ".h")
                pw.println("#pragma once")
                pw.println

                pw.println("namespace NS_" + interface.name)
                pw.println("{")

                pw.println("typedef " + interface.name + " IBase;")
                pw.println("typedef " + interface.name + " *IBasePtr;")
                pw.println

                pw.println("struct ProxyBase")
                pw.println("    : IBase")
                pw.println("{")

                pw.println("    ProxyBase(IBasePtr pimpl) : pimpl_(pimpl) {}")
                pw.println

                interface.methods.foreach((i) => {
                    pw.print("    ")
                    pw.print(i.retType + " " + i.name + "(")

                    val argStrings = i.args.map((arg) => arg.argType + (arg.name match {
                        case Some(name) => " " + name
                        case None => ""
                    }))

                    pw.print(argStrings.mkString(", "))
                    pw.println(") override;")
                })

                pw.println
                pw.println("private:")
                pw.println("    " + "IBasePtr pimpl_;")

                pw.println("};")
                pw.println

                pw.println("}")
                pw.close()
            }

            saveH(interface)
        }

        interfaces.foreach(saveInterface)
    }

    def main(argv: Array[String]) {
        val text = scala.io.Source.fromFile("src.txt").mkString
        val res = parseAll(interfaces, text)

        if(res.successful)
            printInterfaces(res.get)
        else
            println(res)
    }
}

*/