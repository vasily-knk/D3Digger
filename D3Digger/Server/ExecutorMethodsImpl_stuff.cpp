#include "stdafx.h"
#include "ExecutorMethodsImpl.h"
#include "d3d9/Server/IProcMap.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ExecutorMethodsImpl Impl;
}

Impl::AllMethods Impl::getMethods() const
{
    AllMethods methods(static_cast<size_t>(D3D9::Interfaces::TOTAL));

    #define ADD_PROC(name) methods.at(static_cast<size_t>(D3D9::Interfaces::name)) = getMethods##name();

    ADD_PROC(BASE)
    D3D9_LIST_INTERFACES(ADD_PROC)

    #undef ADD_PROC

    return methods;
}

Impl::InterfaceMethods Impl::getMethodsBASE() const
{
    InterfaceMethods methods = 
    {
        make_pair(bind(&ExecutorMethodsImpl::Direct3DCreate9, this, _1, _2), "Direct3DCreate9"),
    };
    return methods;
};

#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE(name) \
    Impl::InterfaceMethods Impl::getMethods##name() const \
    { \
        string interface_name = #name; \
        typedef D3D9::Server::IProc<name> IProc; \
        typedef D3D9::Methods_##name MethodsEnum; \
        auto proc = proc##name##_; \
        InterfaceMethods methods(static_cast<size_t>(MethodsEnum::TOTAL)); 

#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)   

#define MY_END_INTERFACE \
        return methods; \
    }

#define MY_STDMETHOD(name, args) methods.at(static_cast<size_t>(MethodsEnum::name)) = make_pair(bind(&IProc::name, proc, _1, _2), interface_name + string(".") + string(#name));
#define MY_STDMETHOD_(ret_type, name, args) MY_STDMETHOD(name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"

} // namespace Server

} // namespace D3D9
