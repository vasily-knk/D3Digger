package DeclParser

import DeclParser.BaseTypes._

class InOutChecker extends InterfacesProcessor {
  private def checkTypeName(name: String) = {
    val pattern = """IDirect3D(\w*)9""".r

    name match {
      case pattern(str) => true
      case _ => false
    }
  }


  def process(interfaces: Interfaces) {
    val is = interfaces.filter((i) => i.name == "IDirect3DDevice9")
    is.foreach((i) => {
      println(i.name + ":")
      i.methods.foreach((m) => {

        def checkIn(arg: Arg) = {
          val t = arg.argType
          t.ptrDepth match {
            case 2 => false
            case 1 => t.isConst || checkTypeName(t.name) || t.isIn
            case 0 => true
          }
        }

        def checkOut(arg: Arg) = {
          val t = arg.argType
          t.ptrDepth match {
            case 2 => true
            case 1 => !t.isConst && !checkTypeName(t.name)
            case 0 => false
          }
        }

        val in = m.args.filter(checkIn)
        val out = m.args.filter(checkOut)

        def argName(arg: Arg) = arg.name match {
          case Some(name) => name
          case None => "?"
        }

        val inNames = in.map(argName)
        val outNames = out.map(argName)

        if (!inNames.isEmpty || !outNames.isEmpty) {
          println("  " + m.name + ":")
          if (!inNames.isEmpty)
            println("    In : " + inNames.mkString(", "))

          if (!outNames.isEmpty)
            println("    Out: " + outNames.mkString(", "))

        }
      })
    })
  }

}
