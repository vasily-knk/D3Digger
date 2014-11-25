#pragma once

#include "d3d9/Server/IExecutorMethods.h"
#include "d3d9/Server/IProc.h"
#include "d3d9/InterfacesList.h"
#include "d3d9/Server/IProcMap.h"

namespace D3D9
{

namespace Server
{

struct ExecutorMethodsImpl
    : IExecutorMethods
{
    ExecutorMethodsImpl();
    
    Method getMethod(MethodId const &id) const override;

private:
    void initProcs();
    void Direct3DCreate9(BytesPtr srcArgs, BytesPtr dstArgs) const;

private:
    IProcMapPtr procMap_;
    
private:
    typedef vector<Method> InterfaceMethods;
    typedef vector<InterfaceMethods> AllMethods;

    AllMethods methods_;

private:
    AllMethods getMethods() const;
    InterfaceMethods getMethodsBASE() const;

private:
#define ADD_PROC(name) \
    shared_ptr<D3D9::Server::IProc<name>> proc##name##_; \
    vector<Method> getMethods##name() const;

    D3D9_LIST_INTERFACES(ADD_PROC)
#undef ADD_PROC
};

} // namespace Server

} // namespace D3D9
