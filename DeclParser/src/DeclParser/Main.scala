package DeclParser

import scala.io.Source
import BaseTypes._
import java.io.{File, PrintWriter}

object Main extends App {
    val srcText = Source.fromFile("src.txt").mkString
    val interfaces = new ParserImpl().parse(srcText)

    val generator = new ClientProxyGenerator
    val dstText = generator.process(interfaces)

    val pw = new PrintWriter(new File("dst.txt"))
    pw.print(dstText)
    pw.close()
}
