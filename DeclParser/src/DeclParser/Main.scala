package DeclParser

import scala.io.Source
import BaseTypes._
import DeclParser.Main

object Main extends App {
    def checkTypeName(name: String) = {
        val pattern = """IDirect3D(\w*)9""".r

        name match {
            case pattern(str) => true
            case _ => false
        }
    }

    object WrapType extends Enumeration {
        type WrapType = Value
        val None, In, Out = Value
    }
    def checkArgWrap(argType: ArgType) : WrapType.Value = {
        if (!checkTypeName(argType.name))
            WrapType.None
        else if (argType.ptrDepth == 1)
            WrapType.In
        else if (argType.ptrDepth == 2)
            WrapType.Out
        else
            WrapType.None
    }

    val text = Source.fromFile("src.txt").mkString

    val interfaces = new ParserImpl().parse(text)

    interfaces.foreach((i) => {
        println("Interface " + i.name + ": ")
        i.methods.foreach((m) => {
            val ins  = m.args.filter({case arg => checkArgWrap(arg.argType) == WrapType.In })
            val outs = m.args.filter({case arg => checkArgWrap(arg.argType) == WrapType.Out})
            if (!ins.isEmpty || !outs.isEmpty) {
                println(" Method " + m.name)
                if (!ins.isEmpty)
                    println("  In:" + ins.mkString(", "))
                if (!outs.isEmpty)
                    println("  Out:" + outs.mkString(", "))
            }
        })
    })

    //new CodeGenerator().process(interfaces)
}
