package DeclParser

import BaseTypes._

object ServerProcGenerator {
    private val head =
        """#include "stdafx.h"
          |#include "ProcBase.h"
          |""".stripMargin

    private val namespaces = List("D3D9", "Server")

    private case class UnsupportedArgException(t: ArgType) extends RuntimeException("Unsupported arg type: " + t.toString)

    def structType(t: ArgType): ArgType = t match {
        case ArgType("void", _, _, _) => throw UnsupportedArgException(t)

        case ArgType(InOuts.IName(name), false, 1, isIn) => ArgType(InOuts.IName(name), false, 1, isIn)
        case ArgType(InOuts.IName(name), false, 2, isIn) => ArgType(InOuts.IName(name), false, 1, isIn)

        case ArgType("REFIID", false, 0, isIn) => ArgType("IID", false, 0, isIn)
        case ArgType("REFGUID", false, 0, isIn) => ArgType("GUID", false, 0, isIn)

        case ArgType(name, false, 0, isIn) => t
        case ArgType(name, _, 1, isIn) => ArgType("optional<%s>".format(name), false, 0, isIn)
    }

    def deser(arg: Arg): String = arg.argType match {
        case ArgType("void", _, _, _) => throw UnsupportedArgException(arg.argType)

        case ArgType(InOuts.IName(name), false, 1, _) =>
            "%s = procMap_->getPtr<%s>(g.get<ProxyId>())".format(arg.name, InOuts.IName(name))

        case ArgType(typeName, false, 0, _) =>
            "g.get(%s)".format(arg.name)

        case ArgType(typeName, _, 1, _) =>
            "g.get(%s)".format(arg.name)
    }

    def ser(arg: Arg): String = arg.argType match {
        case ArgType(InOuts.IName(_), false, 2, _) =>
            "bytes::put<ProxyId>(procMap_->getProxyID(%s), dstBytes)".format(arg.name)

        case ArgType(typeName, false, 1, _) =>
            "if (%s) bytes::put<%s>(*%s, dstBytes)".format(arg.name, typeName, arg.name)
            //"bytes::put<%s>(args.%s, dstBytes);".format(typeName, arg.name)
    }

    def call(arg: Arg): String = arg.argType match {
        case ArgType(InOuts.IName(name), false, 1, _) => arg.name
        case ArgType(InOuts.IName(name), false, 2, _) => "&" + arg.name

        case ArgType(name, false, 0, _) => arg.name
        case ArgType(name, _, 1, _) => "opt2ptr(%s)".format(arg.name)
    }
}

class ServerProcGenerator extends CodeGeneratorBase(ServerProcGenerator.head, ServerProcGenerator.namespaces) {
    import ServerProcGenerator._

    override def interfaceName(interface: Interface) : String = {
        "ProcBase<" + interface.name + ">"
    }

    override def interfaceHead(interface: Interface) : String =
        """ProcBase<%s>::ProcBase(CreateProcArgs const &args)
          |    : procMap_(args.procMap)
          |{
          |}
          |
          |""".stripMargin.format(interface.name)

    override def methodArgs(interface: Interface, method: StdMethod) : String = {
        "BytesPtr srcBytes, BytesPtr dstBytes"
    }

    override def methodRet(interface: Interface, method: StdMethod) : String = {
        "void"
    }

    override def methodBody(interface: Interface, method: StdMethod) : String = {
        try {
            val sb = new StringBuilder

            val structArgsContent = method.args.map((arg) => structType(arg.argType) + " " + arg.name).mkString(";\r\n    ")

            sb ++=
                """bytes::getter g(srcBytes);
                  |%s *self = procMap_->getPtr<%s>(g.get<ProxyId>());
                  |struct {
                  |    %s;
                  |} args;
                  |(void)args;
                  |""".stripMargin.format(interface.name, interface.name, structArgsContent)

            val structArgs = method.args.map(_ match {
                case Arg(t, name) => Arg(t, "args." + name)
            })

            val ins = structArgs.filter(InOuts.isIn)
            val outs = structArgs.filter(InOuts.isOut)

            ins.foreach((arg) => {
                sb ++= deser(arg)
                sb ++= ";\r\n"
            })

            val isVoid = method.retType match {
                case ArgType("void", _, 0, _) => true
                case ArgType(_, _, 0, _) => false
            }

            if (!isVoid)
                sb ++= method.retType.toString + " " + "res = "

            val callArgs = structArgs.map(call).mkString(", ")

            sb ++= "self->" + method.name + "(" + callArgs + ");\r\n"

            if (!isVoid)
                sb ++= "bytes::put<%s>(res, dstBytes);\r\n".format(method.retType.name)

            outs.foreach((arg) => {
                sb ++= ser(arg)
                sb ++= ";\r\n"
            })

            sb.toString()
        } catch {
            case e : UnsupportedArgException => "throw std::runtime_error(\"Method has unsupported arg: %s\");".format(e.t.toString)
        }
    }

    def methodBody1(interface: Interface, method: StdMethod) : String = {
        val sb = new StringBuilder

        def argInStruct(arg: Arg) = {
            def fixType(t: ArgType) = {
                /*if (InOuts.checkTypeName(t.name)) {
                    t match {
                        case ArgType(name, false, 1, isIn) => ArgType(name, false, 1, isIn)
                        case ArgType(name, false, 2, isIn) => ArgType(name, false, 1, isIn)
                    }
                } else {*/
                    t match {
                        case ArgType("void", _, _, _) => throw UnsupportedArgException(t)

                        case ArgType(InOuts.IName(name), false, 1, isIn) => ArgType(InOuts.IName(name), false, 1, isIn)
                        case ArgType(InOuts.IName(name), false, 2, isIn) => ArgType(InOuts.IName(name), false, 1, isIn)

                        case ArgType("REFIID", false, 0, isIn) => ArgType("IID", false, 0, isIn)
                        case ArgType("REFGUID", false, 0, isIn) => ArgType("GUID", false, 0, isIn)

                        case ArgType(name, false, 0, isIn) => t
                        case ArgType(name, _, 1, isIn) => ArgType("optional<%s>".format(name), false, 0, isIn)
                    }
                //}
            }
            Arg(fixType(arg.argType), arg.name)
        }

        def needsAmp(t: ArgType) = {
            if (InOuts.checkTypeName(t.name)) {
                t match {
                    case ArgType(_, false, 1, _) => false
                    case ArgType(_, false, 2, _) => true
                }
            } else {
                t match {
                    case ArgType(_, false, 0, _) => false
                    case ArgType(_, _, 1, _) => true
                }
            }
        }

        try {

            val structArgs = method.args.map(argInStruct)
            val structArgsStr = structArgs.mkString(";\r\n    ")

            sb ++=
                """bytes::getter g(srcBytes);
                  |%s *self = procMap_->getPtr<%s>(g.get<ProxyId>());
                  |struct {
                  |    %s;
                  |} args;
                  |(void)args;
                  |""".stripMargin.format(interface.name, interface.name, structArgsStr)

            val ins = method.args.filter(InOuts.isIn).map(argInStruct)
            val outs = method.args.filter(InOuts.isOut).map(argInStruct)

            ins.foreach((arg) => {
                val str = arg.argType match {
                    case ArgType(InOuts.IName(name), false, 1, _) => "args.%s = procMap_->getPtr<%s>(g.get<ProxyId>());\r\n".format(arg.name, InOuts.IName(name))
                    case ArgType(name, false, 0, _) => "args.%s = g.get<%s>();\r\n".format(arg.name, name)
                }
                sb ++= str
            })

            //sb ++= "assert(g.left() == 0);\r\n"

            val isVoid = method.retType match {
                case ArgType("void", _, 0, _) => true
                case ArgType(_, _, 0, _) => false
            }

            if (!isVoid)
                sb ++= method.retType.toString + " " + "res = "

            val callArgs0 = method.args.map(_ match {
                case Arg(argType, name) => Arg(argType, "args." + name)
            })

            val callArgs = callArgs0.map((arg) => {
                arg.argType match {
                    case ArgType(InOuts.IName(name), false, 1, isIn) => arg.name
                    case ArgType(InOuts.IName(name), false, 2, isIn) => "&" + arg.name

                    case ArgType(name, false, 0, isIn) => arg.name
                    case ArgType(name, _, 1, isIn) => "opt2ptr(%s)".format(arg.name)
                }
            })


            sb ++= "self->" + method.name + "(" + callArgs.mkString("," ) + ");\r\n"

            if (!isVoid)
                sb ++= "bytes::put<%s>(res, dstBytes);\r\n".format(method.retType.name)

            outs.foreach((arg) => {
                val str = arg.argType match {
                    case ArgType(InOuts.IName(_), false, 1, _) => "bytes::put<ProxyId>(procMap_->getProxyID(args.%s), dstBytes);".format(arg.name)
                    case ArgType(typeName, false, 0, _) => "bytes::put<%s>(args.%s, dstBytes);".format(typeName, arg.name)
                }
                sb ++= str
                sb ++= "\r\n"
            })


            sb.toString()
        } catch {
            case e : UnsupportedArgException => "throw std::runtime_error(\"Method has unsupported arg: %s\");".format(e.t.toString)
        }

    }

}
