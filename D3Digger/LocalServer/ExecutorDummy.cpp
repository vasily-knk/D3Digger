#include "stdafx.h"
#include "ExecutorDummy.h"

namespace D3D9
{
namespace Client
{
    
ExecutorDummy::ExecutorDummy()
    : methods_(Server::createProcMethods())
{
}

ExecutorDummy::~ExecutorDummy()
{
}


BytesPtr ExecutorDummy::runSync(MethodId const& id, BytesPtr srcArgs) 
{
    updateTraffic(id, srcArgs->size());
    
    BytesPtr dstArgs = bytes::make();
    Method method = methods_->getMethod(id);
    method.first(srcArgs, dstArgs);

    return dstArgs;
}

void ExecutorDummy::runAsync(MethodId const &id, BytesPtr args) 
{
	runSync(id, args);
}

void ExecutorDummy::updateTraffic(MethodId const &id, size_t size)
{
    if (traffic_.count(id) == 0)
        traffic_.emplace(id, 0);

    traffic_.at(id) += size;
}

} // namespace Client

} // namespace D3D9