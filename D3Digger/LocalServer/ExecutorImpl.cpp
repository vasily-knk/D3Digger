#include "stdafx.h"
#include "ExecutorImpl.h"

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
    
    
IExecutorPtr createExecutor()
{
	return make_shared<ExecutorImpl>();
}
	

ExecutorImpl::ExecutorImpl()
    : serviceWork_(service_)
    , serviceThread_(bind(runService, &service_))
    , isComplete_(true)
    , procMap_(Server::createProcMap())
{
    initProcs();
}

void ExecutorImpl::initProcs()
{
    Server::CreateProcArgs args;
    args.procMap = procMap_;

#define EXECUTORIMPL_INIT_PROC(name) proc##name##_ = Server::createProc<name>(args);
    D3D9_LIST_FINAL_INTERFACES(EXECUTORIMPL_INIT_PROC)
#undef EXECUTORIMPL_INIT_PROC
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
    struct 
    {
        UINT SDKVersion;
    } args;

    bytes::read_proc rp(srcArgs);
    args.SDKVersion = rp.operator()<UINT>();
    
    static auto dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    typedef IDirect3D9* (WINAPI *fn_t)(UINT);

    auto fn = reinterpret_cast<fn_t>(GetProcAddress(dll, "Direct3DCreate9"));

    IDirect3D9 *ptr = fn(args.SDKVersion);
    assert(ptr);

    bytes::write_proc wp(dstArgs);
    uint32_t id = procMap_->getProxyID(ptr);
    wp(id);
}

ExecutorImpl::Method ExecutorImpl::getMethod(MethodId const &id) const
{
    static auto methods = getMethods();
    return methods.at(static_cast<size_t>(id.first)).at(id.second);
}



} // namespace Client

} // namespace D3D9