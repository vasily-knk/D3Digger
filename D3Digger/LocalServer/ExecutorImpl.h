#pragma once

#include "d3d9/Client/IExecutor.h"
#include "d3d9/Server/IProc.h"
#include "d3d9/InterfacesList.h"
#include "d3d9/Server/IProcMap.h"

namespace D3D9
{
namespace Client
{

struct ExecutorImpl
	: IExecutor
{
    
    ExecutorImpl();
	~ExecutorImpl();
            
    BytesPtr runSync(MethodId const& id, BytesPtr args) override;
	void runAsync(MethodId const &id, BytesPtr args) override;

private:
    void initProcs();

    typedef function<void(BytesPtr, BytesPtr)> Method;
    Method getMethod(MethodId const &id) const;

    void execute(MethodId const &id, BytesPtr srcArgs, BytesPtr dstArgs);
    void Direct3DCreate9(BytesPtr srcArgs, BytesPtr dstArgs) const;

private:
    IOService service_;
    IOService::work serviceWork_;
    Thread serviceThread_;

private:
    mutex mutex_;
    condition_variable cond_;
    bool isComplete_;

    Server::IProcMapPtr procMap_;

private:
    vector<vector<Method>> getMethods() const;
    vector<Method> getMethodsBASE() const;

#define ADD_PROC(name) \
    shared_ptr<D3D9::Server::IProc<name>> proc##name##_; \
    vector<Method> getMethods##name() const;

    D3D9_LIST_INTERFACES(ADD_PROC)
#undef ADD_PROC
};
	
	
} // namespace Client

} // namespac