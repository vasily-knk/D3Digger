#include "stdafx.h"
#include "ExecutorASIO.h"

namespace D3D9
{
namespace Client
{
	
namespace
{
    void runService(IOService *service)
    {
        service->run();
    }
} // namespace
    
    
ExecutorASIO::ExecutorASIO()
    : serviceWork_(service_)
    , serviceThread_(bind(runService, &service_))
    , isComplete_(true)
    , methods_(Server::createProcMethods())
{
}

ExecutorASIO::~ExecutorASIO()
{
    service_.post(bind(&Service::stop, &service_));
    serviceThread_.join();
}


BytesPtr ExecutorASIO::runSync(MethodId const& id, BytesPtr args) 
{
    BytesPtr dstArgs = bytes::make();

    std::unique_lock<std::mutex> lock(mutex_);
    Assert(isComplete_);
    isComplete_ = false;

    service_.post(bind(&ExecutorASIO::execute, this, id, args, dstArgs));

    cond_.wait(lock, [this]() { return isComplete_; });

    return dstArgs;
}

void ExecutorASIO::runAsync(MethodId const &id, BytesPtr args) 
{
	Method method = methods_->getMethod(id);
    service_.post(bind(method.first, args, bytes::make()));
}

void ExecutorASIO::execute(MethodId const &id, BytesPtr srcArgs, BytesPtr dstArgs)
{
    // Thread: service
    Assert(this_thread::get_id() == serviceThread_.get_id());

    Method method = methods_->getMethod(id);
    
    method.first(srcArgs, dstArgs);
    
    std::unique_lock<mutex> lock(mutex_);
    isComplete_ = true;
    cond_.notify_all();
}


} // namespace Client

} // namespace D3D9