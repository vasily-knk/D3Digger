import java.io.{File, PrintWriter}
import scala.io.Source

object Main extends App {
    val srcText = Source.fromFile("d3d10_decl.h").mkString
    val interfaces = new ParserImpl().parse(srcText)

    val tasks = List (
        ("proxy.h", new ProxyHeaderGen)
    )

    tasks.foreach { case (filename, generator) => {
        val text = generator.generate(interfaces)

        val pw = new PrintWriter(new File(filename))
        pw.print(text)
        pw.close()
    }}

}
