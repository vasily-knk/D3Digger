#include "stdafx.h"
#include "ExecutorImpl.h"

namespace D3D9
{
namespace Client
{
	
IExecutorPtr createExecutor()
{
	return make_shared<ExecutorImpl>();
}
	

ExecutorImpl::ExecutorImpl()
    : serviceWork_(service_)
    , serviceThread_(bind(&IOService::run, &service_))
    , isComplete_(true)
{

}

ExecutorImpl::~ExecutorImpl()
{
    service_.post(bind(&IOService::stop, &service_));
    serviceThread_.join();
}


BytesPtr ExecutorImpl::runSync(MethodId const& id, BytesPtr args) 
{
	Method method = getMethod(id);

    BytesPtr dstArgs = bytes::make();

    std::unique_lock<std::mutex> lock(mutex_);
    assert(isComplete_);
    isComplete_ = false;

    service_.post(bind(&ExecutorImpl::execute, this, id, args, dstArgs));

    cond_.wait(lock, [this]() { return isComplete_; });

    return dstArgs;
}

void ExecutorImpl::runAsync(MethodId const &id, BytesPtr args) 
{
	Method method = getMethod(id);
    service_.post(bind(method, args, bytes::make()));
}

void ExecutorImpl::execute(MethodId const &id, BytesPtr srcArgs, BytesPtr dstArgs)
{
    // Thread: service
    assert(this_thread::get_id() == serviceThread_.get_id());

    Method method = getMethod(id);
    method(srcArgs, dstArgs);
    
    std::unique_lock<mutex> lock(mutex_);
    isComplete_ = true;
    cond_.notify_all();
}

void ExecutorImpl::Direct3DCreate9(BytesPtr srcArgs, BytesPtr dstArgs) const
{   
    (void)srcArgs;
    (void)dstArgs;

    int i = 5;
}

ExecutorImpl::Method ExecutorImpl::getMethod(MethodId const &id) const
{
    static auto methods = getMethods();
    return methods.at(static_cast<size_t>(id.first)).at(id.second);
}



} // namespace Client

} // namespace D3D9