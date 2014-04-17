package DeclParser

import BaseTypes._

trait InterfacesParser {
    case class ParseException(msg: String) extends RuntimeException(msg)

    def parse(text: String) : Interfaces
}
