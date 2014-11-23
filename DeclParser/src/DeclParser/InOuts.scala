package DeclParser

import BaseTypes._

object InOuts {
    def isIn(arg: Arg) = arg.argType match {
        case ArgType(_, _, _, true) => true
        case ArgType(_, _, 0, _) => true

        case ArgType("void", _, 1, _) => {
            false
        } // Fixme

        case ArgType("HANDLE", _, 1, _) => false
        case ArgType(_, _, 1, _) => true
        //case ArgType(typeName, false, 1, _) => checkTypeName(typeName)
        case ArgType(_, _, 2, _) => false
    }

    def isOut(arg: Arg) = arg.argType match {
        case ArgType(_, _, 0, _) => false
        case ArgType("void", _, 1, _) => false // Fixme
        case ArgType("HANDLE", _, 1, _) => false
        case ArgType(_, true, 1, _) => false
        case ArgType(typeName, false, 1, _) => !checkTypeName(typeName)
        case ArgType(typeName, _, 2, _) => checkTypeName(typeName)
    }

    object IName {
        val pattern =  """IDirect3D(\w*)9""".r
        def apply(name: String) = "IDirect3D%s9".format(name)
        def unapply(str: String) = pattern.unapplySeq(str) match {
            case Some(list) => Some(list(0))
            case None => None
        }
    }

    def checkTypeName(name: String) = {
        val pattern = IName.pattern

        name match {
            case pattern(str) => true
            case _ => false
        }
    }
}
