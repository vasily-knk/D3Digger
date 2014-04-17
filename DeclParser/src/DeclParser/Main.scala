package DeclParser

import scala.io.Source

object Main extends App {
    val text = Source.fromFile("src.txt").mkString

    val interfaces = new ParserImpl().parse(text)

    new CodeGenerator().process(interfaces)
}
