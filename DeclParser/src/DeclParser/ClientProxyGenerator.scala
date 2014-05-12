package DeclParser

import DeclParser.BaseTypes._

object ClientProxyGenerator {
    case class MethodImpl()

    private val head =
        """
          |#include "stdafx.h"
          |#include "ProxyBase.h"
          |""".stripMargin

    private val namespaces = List("D3D9", "Client")

    private def getIns(m: StdMethod): Args = m.args.filter((arg) => arg.argType match {
        case ArgType(_, _, 0, _) => true
        case ArgType(_, true, 1, _) => true
        case ArgType(typeName, false, 1, _) => checkTypeName(typeName)
        case ArgType(_, _, 2, _) => false
    })

    private def getOuts(m: StdMethod): Args = List()

    private def isAsync(m: StdMethod) = {
        val noRet = m.retType match {
            case ArgType("void", _, 0, _) => true
            case ArgType("HRESULT", _, 0, _) => true
            case _ => false
        }
        noRet && getOuts(m).isEmpty
    }

    private def checkTypeName(name: String) = {
        val pattern = """IDirect3D(\w*)9""".r

        name match {
            case pattern(str) => true
            case _ => false
        }
    }

    private def wrapStr(arg: Arg): String = arg.argType match {
        case ArgType(_, _, 0, _) => arg.name.get
        case ArgType(typeName, _, 1, _) =>
            if (checkTypeName(typeName))
                "dynamic_cast<IProxy<%s>*>(%s)->getId()".format(typeName, arg.name.get)
            else
                "*%s".format(arg.name.get)
    }


}

class ClientProxyGenerator extends CodeGeneratorBase(ClientProxyGenerator.head, ClientProxyGenerator.namespaces) {
    import ClientProxyGenerator._
    def interfaceName(interface: Interface) : String = {
        "ProxyBase<" + interface.name + ">"
    }
    def interfaceHead(interface: Interface) : String =
        """ProxyBase<%s>::ProxyBase<%s>(ProxyId id)
          |    : id_(id)
          |    , refcount_(1)
          |{
          |}
          |
          |""".stripMargin.format(interface.name, interface.name)

    def methodBody(interface: Interface, method: StdMethod) : String = {
        val ins = getIns(method)

        val sb = new StringBuilder

        sb ++=
            """BytesPtr inBytes = bytes::make();
              |inBytes->put(getId());
              |""".stripMargin

        ins.foreach((a) => {
            sb ++= "inBytes->put(%s);".format(wrapStr(a))
            sb ++= "\r\n"
        })

        val methodId = "makeMethodId(Interfaces::%s, Methods_%s::%s)".format(interface.name, interface.name, method.name)

        if (isAsync(method)) {
            sb ++= "getGlobal().executor().runAsync(%s, inBytes);\r\n".format(methodId)
            sb ++= (method.retType match {
                case ArgType("void", _, 0, _) => ""
                case ArgType("HRESULT", _, 0, _) => "return D3D_OK;\r\n"
            })
        } else {
            sb ++= "BytesPtr outBytes = getGlobal().executor().runSync(%s, inBytes);\r\n".format(methodId)

            val isVoid = method.retType match {
                case ArgType("void", _, 0, _) => true
                case _ => false
            }

            if (!isVoid) {
                val retType = "sss"
                sb ++= "%s ret = outBytes.get<%s>();\r\n".format(retType, retType)
            }

            

            if (!isVoid)
                sb ++= "return ret;\r\n"
        }

        sb.toString()
    }
}
