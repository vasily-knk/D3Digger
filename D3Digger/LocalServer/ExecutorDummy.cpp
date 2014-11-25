#include "stdafx.h"
#include "ExecutorDummy.h"

namespace D3D9
{
namespace Client
{
    
ExecutorDummy::ExecutorDummy()
    : methods_(Server::createExecutorMethods())
{
}

ExecutorDummy::~ExecutorDummy()
{
}


BytesPtr ExecutorDummy::runSync(MethodId const& id, BytesPtr srcArgs) 
{
    BytesPtr dstArgs = bytes::make();
    Method method = methods_->getMethod(id);
    method.first(srcArgs, dstArgs);

    return dstArgs;
}

void ExecutorDummy::runAsync(MethodId const &id, BytesPtr args) 
{
	runSync(id, args);
}

} // namespace Client

} // namespace D3D9