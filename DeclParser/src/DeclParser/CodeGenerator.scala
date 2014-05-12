package DeclParser

import BaseTypes._

trait CodeGenerator {
    def process(interfaces: Interfaces): String
}
