package DeclParser

import scala.io.Source
import BaseTypes._
import java.io.{File, PrintWriter}

object Main extends App {
    val srcText = Source.fromFile("src.txt").mkString
    val interfaces = new ParserImpl().parse(srcText)

    def go(proc: CodeGenerator, filename: String) {
        val text = proc.process(interfaces)

        val pw = new PrintWriter(new File(filename))
        pw.print(text)
        pw.close()
    }

    //new PPChecker().check(interfaces)
    go(new ClientProxyGenerator, "../D3Digger/Client/ProxyBase.cpp")
    go(new ServerProcGenerator, "../D3Digger/Server/ProcBase.cpp")
}
