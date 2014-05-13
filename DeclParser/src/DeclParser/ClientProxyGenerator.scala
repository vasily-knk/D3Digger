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
        case ArgType("void", _, 1, _) => {
            println("void*: " + m.name)
            false
        } // Fixme
        case ArgType(_, true, 1, _) => true
        case ArgType(typeName, false, 1, _) => checkTypeName(typeName)
        case ArgType(_, _, 2, _) => false
    })

    private def getOuts(m: StdMethod): Args = m.args.filter((arg) => arg.argType match {
        case ArgType(_, _, 0, _) => false
        case ArgType("void", _, 1, _) => false // Fixme
        case ArgType(_, true, 1, _) => false
        case ArgType(typeName, false, 1, _) => !checkTypeName(typeName)
        case ArgType(typeName, _, 2, _) => checkTypeName(typeName)
    })

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

    private def unwrapStr(arg: Arg): String = arg.argType match {
        case ArgType(typeName, false, 1, _) => "g.get<%s>()".format(typeName)
        case ArgType(typeName, _, 2, _) =>
            if (checkTypeName(typeName))
                "getGlobal().proxyMap().getById<%s>(g.get<ProxyId>())".format(typeName)
            else
                throw new RuntimeException("Unexpected out arg: " + arg)
    }
}

class ClientProxyGenerator extends CodeGeneratorBase(ClientProxyGenerator.head, ClientProxyGenerator.namespaces) {
    import ClientProxyGenerator._
    override def interfaceName(interface: Interface) : String = {
        "ProxyBase<" + interface.name + ">"
    }
    override def interfaceHead(interface: Interface) : String =
        """ProxyBase<%s>::ProxyBase(ProxyId id)
          |    : id_(id)
          |    , refcount_(1)
          |{
          |}
          |
          |""".stripMargin.format(interface.name)

    override def methodBody(interface: Interface, method: StdMethod) : String = method.name match {
        case "AddRef" => methodBodyAddRef(interface, method)
        case "Release" => methodBodyRelease(interface, method)
        case "QueryInterface" => methodBodyQueryInterface(interface, method)
        case _ => methodBodyGeneric(interface, method)
    }

    private def getMethodId(interface: Interface, method: StdMethod) = {
        "makeMethodId(Interfaces::%s, Methods_%s::%s)".format(interface.name, interface.name, method.name)
    }

    private def methodBodyAddRef(interface: Interface, method: StdMethod) : String = {
        """assert(refcount_ > 0);
          |++refcount_;
          |return refcount_;
          |""".stripMargin
    }
    private def methodBodyRelease(interface: Interface, method: StdMethod) : String = {
        """--refcount_;
          |assert(refcount_ >= 0);
          |if (refcount_ == 0)
          |{
          |    BytesPtr inBytes = bytes::make();
          |    bytes::put(getId(), inBytes);
          |    getGlobal().executor().runAsync(%s, inBytes);
          |    emitDeleted();
          |    delete this;
          |    return 0;
          |} else
          |    return refcount_;
          |""".stripMargin.format(getMethodId(interface, method))
    }
    private def methodBodyQueryInterface(interface: Interface, method: StdMethod) : String = {
        val ptrArgName = method.args(1).name.get

        """if (!%s)
          |    return E_POINTER;
          |else
          |{
          |    *%s = nullptr;
          |    return E_NOINTERFACE;
          |}
          |""".stripMargin.format(ptrArgName, ptrArgName)
    }

    private def methodBodyGeneric(interface: Interface, method: StdMethod) : String = {
        val ins = getIns(method)
        val outs = getOuts(method)

        val sb = new StringBuilder

        sb ++=
            """BytesPtr inBytes = bytes::make();
              |bytes::put(getId(), inBytes);
              |""".stripMargin

        ins.foreach((a) => {
            sb ++= "bytes::put(%s, inBytes);".format(wrapStr(a))
            sb ++= "\r\n"
        })

        sb ++= "\r\n"

        val methodId = getMethodId(interface, method)

        if (isAsync(method)) {
            sb ++= "getGlobal().executor().runAsync(%s, inBytes);\r\n\r\n".format(methodId)
            sb ++= (method.retType match {
                case ArgType("void", _, 0, _) => ""
                case ArgType("HRESULT", _, 0, _) => "return D3D_OK;\r\n"
            })
        } else {
            sb ++= "BytesPtr outBytes = getGlobal().executor().runSync(%s, inBytes);\r\n\r\n".format(methodId)
            sb ++= "bytes::getter g(outBytes);\r\n"

            val isVoid = method.retType match {
                case ArgType("void", _, 0, _) => true
                case ArgType(_, _, 0, _) => false
            }

            if (!isVoid) {
                val retTypeName = method.retType.name
                sb ++= "%s ret = g.get<%s>();\r\n".format(retTypeName, retTypeName)
            }

            outs.foreach((a) => {
                sb ++= "*%s = %s;\r\n".format(a.name.get, unwrapStr(a))
            })

            if (!isVoid)
                sb ++= "return ret;\r\n"
        }

        sb.toString()
    }
}
