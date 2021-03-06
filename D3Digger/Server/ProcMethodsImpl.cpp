#include "stdafx.h"
#include "ProcMethodsImpl.h"
#include "d3d9/Server/IProc.h"
#include "d3d9/InterfacesList.h"
#include "d3d9/Server/IProcMap.h"

namespace D3D9
{

namespace Server
{

IExecutorMethodsPtr createProcMethods()
{
    return make_shared<ProcMethodsImpl>();
}

ProcMethodsImpl::ProcMethodsImpl()
    : procMap_(createProcMap())
{
    initProcs();
    methods_ = getMethods();
}

void ProcMethodsImpl::initProcs()
{
    Server::CreateProcArgs args;
    args.procMap = procMap_;

#define EXECUTORIMPL_INIT_PROC(name) proc##name##_ = Server::createProc<name>(args);
    D3D9_LIST_FINAL_INTERFACES(EXECUTORIMPL_INIT_PROC)
#undef EXECUTORIMPL_INIT_PROC
}

IProcMethods::Method ProcMethodsImpl::getMethod(MethodId const &id) const 
{
    return methods_.at(static_cast<size_t>(id.first)).at(id.second);
}

void ProcMethodsImpl::Direct3DCreate9(BytesPtr srcArgs, BytesPtr dstArgs) const
{
    struct 
    {
        UINT SDKVersion;
    } args;

    bytes::read_proc rp(srcArgs);
    rp(args.SDKVersion);
    
    static auto dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    typedef IDirect3D9* (WINAPI *fn_t)(UINT);

    auto fn = reinterpret_cast<fn_t>(GetProcAddress(dll, "Direct3DCreate9"));

    IDirect3D9 *ptr = fn(args.SDKVersion);
    Assert(ptr);

    bytes::write_proc wp(dstArgs);
    uint32_t id = procMap_->getProxyID(ptr);
    wp(id);
}


} // namespace Server

} // namespace D3D9
