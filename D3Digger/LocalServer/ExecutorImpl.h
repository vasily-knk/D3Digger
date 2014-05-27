#pragma once

#include "d3d9/IExecutor.h"

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
    typedef function<void(BytesPtr, BytesPtr)> Method;
    Method getMethod(MethodId const &id);

    void execute(MethodId const &id, BytesPtr srcArgs, BytesPtr dstArgs);

private:
    IOService service_;
    IOService::work serviceWork_;
    Thread serviceThread_;

private:
    mutex mutex_;
    condition_variable cond_;
    bool isComplete_;
};
	
	
} // namespace Client

} // namespac