import scala.io.Source

object Main extends App {
    def processInterfaces(interfaces: List[Interface])
    {
        val a = interfaces
    }

    val srcText = Source.fromFile("d3d10_decl.h").mkString
    val interfaces = new ParserImpl().parse(srcText)
    processInterfaces(interfaces)
}
