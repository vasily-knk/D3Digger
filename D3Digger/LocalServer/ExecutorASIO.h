#pragma once

#include "d3d9/Client/IExecutor.h"
#include "d3d9/Server/IProcMethods.h"
#include "common/asio_wrapper.h"

namespace D3D9
{
namespace Client
{

struct ExecutorASIO
	: IExecutor
{
    ExecutorASIO();
	~ExecutorASIO();
            
    BytesPtr runSync(MethodId const& id, BytesPtr args) override;
	void runAsync(MethodId const &id, BytesPtr args) override;

private:
    void execute(MethodId const &id, BytesPtr srcArgs, BytesPtr dstArgs);

private:
    typedef IOService Service;
    IOService service_;
    IOService::work serviceWork_;
    Thread serviceThread_;

private:
    mutex mutex_;
    condition_variable cond_;
    bool isComplete_;

private:
    typedef Server::IProcMethods::Method Method;
    Server::IExecutorMethodsPtr methods_;
};
	
	
} // namespace Client

} // namespace D3D9