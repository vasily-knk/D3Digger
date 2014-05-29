package DeclParser

import BaseTypes._

class PPChecker {
    def check(interfaces: Interfaces) {
        interfaces.foreach((i) => {
            i.methods.foreach((m) => {
                val args2 = m.args.filter((arg) => arg.argType.ptrDepth >= 2 && !InOuts.checkTypeName(arg.argType.name))
                if (!args2.isEmpty) {
                    println(i.name + "." + m.name + ": " + args2.mkString(", "))
                }
            })
        })
    }
}
