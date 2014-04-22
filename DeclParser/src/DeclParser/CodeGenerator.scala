package DeclParser

import BaseTypes._

object CodeGenerator {
    def stripName(name: String) = {
        class BadNameException extends RuntimeException

        val pattern = """IDirect3D(\w*)9""".r

        val stripped = name match {
            case pattern(str) => str
            case _ => throw new BadNameException()
        }

        if (stripped.isEmpty) "D3D" else stripped
    }

    val baseNamespaces = Nil //List("D3Digger", "D3D9")
    private def proxyFilename(name: String) = "gen/ProxyBase_" + name

    private type PW = java.io.PrintWriter

    private def openNamespaces(namespaces: List[String]) : String = {
        namespaces.map(
            (ns) => "namespace " + ns + "\r\n{\r\n"
        ).mkString("")
    }

    private def closeNamespaces(namespaces: List[String]) : String = {
        namespaces.map(
            (ns) => "} // namespace " + ns + "\r\n\r\n"
        ).mkString("")
    }

    private def fixUnnamedArgs(args: Args) : Args = {
        var counter: Int = 0

        def newName(): String = {
            val res = "unnamed" + counter.toString
            counter += 1
            res
        }

        args.map(
            (arg) => Arg(arg.argType, arg.name match {
                case Some(s) => Some(s)
                case None => Some(newName())
            })
        )
    }

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
}

class CodeGenerator extends InterfacesProcessor {
    import CodeGenerator._

    private def writeHeader(pw: PW) {
        pw.println(
            """#include "stdafx.h"
              |#include "ProxyBase.h"
            """.stripMargin)
    }

    private def processInterface(i: Interface, pw: PW) {
        pw.println(
            """template<>
              |shared_ptr<IProxy<%s>> createProxy<%s>(%s *pimpl)
              |{
              |    return make_shared<ProxyBase<%s>>(pimpl);
              |}
            """.stripMargin.format(i.name, i.name, i.name, i.name))

        pw.println(
            """ProxyBase<%s>::ProxyBase(%s *pimpl)
              |    : pimpl_(pimpl)
              |    , extRefCount_(1)
              |{
              |}
            """.stripMargin.format(i.name, i.name))

        pw.println(
            """%s *ProxyBase<%s>::getPImpl()
              |{
              |    return pimpl_;
              |}
            """.stripMargin.format(i.name, i.name))


        i.methods.foreach((m) => {
            val args = fixUnnamedArgs(m.args)

            val argsString = args.map((arg) => arg.argType + (arg.name match {
                case Some(name) => " " + name
            })).mkString(", ")

            def checkVoid(t: ArgType) = t.name == "void" && t.ptrDepth == 0

            //val returnStr = if (checkVoid(m.retType)) "return " else ""

            val argsStringOnlyNames = args.map((arg) => arg.name match {
                case Some(name) => name
            }).mkString(", ")

            val pimplCall = "pimpl_->%s(%s)".format(m.name, argsStringOnlyNames)

            val body = m.name match {
                case "AddRef" =>
                    """    auto refCount = %s;
                      |    ++extRefCount_;
                      |    return refCount;
                    """.stripMargin.format(pimplCall)
                case "Release" =>
                    """    auto refCount = %s;
                      |    --extRefCount_;
                      |    if (refCount == 0 && extRefCount_ == 0)
                      |    {
                      |        detachProxy(pimpl_);
                      |        pimpl_ = nullptr;
                      |    }
                      |    return refCount;
                    """.stripMargin.format(pimplCall)
                case "QueryInterface" =>
                    """    assert(false); // Not implemented
                      |    return E_FAIL;
                    """.stripMargin
                case _ => {
                    val unwraps = m.args.filter({case arg => checkArgWrap(arg.argType) == WrapType.In })
                    val wraps = m.args.filter({case arg => checkArgWrap(arg.argType) == WrapType.Out})

                    val unwrapStrs = unwraps.map({case arg => "%s = unwrapProxy<%s>(%s);".format(arg.name.get, arg.argType.name, arg.name.get)})
                    val wrapStrs = wraps.map({case arg => "*%s = wrapProxy<%s>(*%s).get();".format(arg.name.get, arg.argType.name, arg.name.get)})

                    val unwrapsStr = unwrapStrs.mkString(" ")
                    val wrapsStr = wrapStrs.mkString(" ")

                    val storeStr = if (checkVoid(m.retType)) "" else "auto res = "
                    val returnStr = if (checkVoid(m.retType)) "" else "return res"

                    """   %s
                      |   %s%s;
                      |   %s
                      |   %s;
                    """.stripMargin.format(unwrapsStr, storeStr, pimplCall, wrapsStr, returnStr)
                }
            }

            pw.println(
                """%s ProxyBase<%s>::%s(%s)
                  |{
                  |    LOG("%s.%s");
                  |%s
                  |}
                """.stripMargin.format(m.retType, i.name, m.name, argsString, i.name, m.name, body))
        })
    }

    def process(interfaces: Interfaces) {
        val pw = new PW("C:\\my\\D3Digger\\D3Digger\\D3D9\\ProxyBase.cpp")
        writeHeader(pw)
        interfaces.foreach(processInterface(_, pw))
        pw.close()
    }
}
