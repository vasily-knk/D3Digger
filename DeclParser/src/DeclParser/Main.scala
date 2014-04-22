package DeclParser

import scala.io.Source
import BaseTypes._
import DeclParser.Main

object Main extends App {
    def printReturns(interfaces: Interfaces){
        def checkMethod(m: StdMethod) = {
            val l = m.args.filter((arg) => !CodeGenerator.checkTypeName(arg.argType.name) && arg.argType.ptrDepth == 2)
            !l.isEmpty
        }

        interfaces.foreach((i) => {
            i.methods.foreach((m) => {
                if (checkMethod(m)) {
                    println(i.name + "." + m.name)
                }
            })
        })
    }


    val text = Source.fromFile("src.txt").mkString

    val interfaces = new ParserImpl().parse(text)
    //printReturns(interfaces)

    new CodeGenerator().process(interfaces)
}
