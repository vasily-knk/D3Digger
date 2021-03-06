#pragma once

#include "common/bytes.h"
#include "d3d9/Methods.h"

namespace D3D9
{

namespace Server
{

struct IProcMethods
    : Interface
{
    typedef function<void(BytesPtr, BytesPtr)> MethodFn;
    typedef pair<MethodFn, string> Method;
    
    virtual Method getMethod(MethodId const &id) const = 0;
};

typedef shared_ptr<IProcMethods> IExecutorMethodsPtr;

IExecutorMethodsPtr createProcMethods();

} // namespace Server

} // namespace D3D9
