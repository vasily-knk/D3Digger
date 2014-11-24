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
            "%s = procMap_->getPtr<%s>(rp.operator()<ProxyId>())".format(arg.name, InOuts.IName(name))

        case ArgType(typeName, false, 0, _) =>
            "rp(%s)".format(arg.name)

        case ArgType(typeName, _, 1, _) =>
            "rp(%s)".format(arg.name)
    }

    def ser(arg: Arg): String = arg.argType match {
        case ArgType(InOuts.IName(_), false, 2, _) =>
            "wp(procMap_->getProxyID(%s))".format(arg.name)

        case ArgType(typeName, false, 1, _) =>
            "if (%s) wp(*%s)".format(arg.name, arg.name)
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
                """bytes::read_proc rp(srcBytes);
                  |%s *self = procMap_->getPtr<%s>(rp.operator()<ProxyId>());
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

            sb ++= "bytes::write_proc wp(dstBytes);\r\n"

            if (!isVoid) {
                sb ++= "wp(res);\r\n"
                sb ++= "CHECK_PROC_RESULT(res);\r\n"
            }

            outs.foreach((arg) => {
                sb ++= ser(arg)
                sb ++= ";\r\n"
            })

            sb.toString()
        } catch {
            case e : UnsupportedArgException => "throw std::runtime_error(\"Method has unsupported arg: %s\");".format(e.t.toString)
        }
    }

}
