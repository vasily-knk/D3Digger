#pragma once

#include "d3d9/Client/IExecutor.h"
#include "d3d9/Server/IExecutorMethods.h"

namespace D3D9
{
namespace Client
{

struct ExecutorDummy
	: IExecutor
{
    ExecutorDummy();
	~ExecutorDummy();
            
    BytesPtr runSync(MethodId const& id, BytesPtr args) override;
	void runAsync(MethodId const &id, BytesPtr args) override;

private:
    typedef Server::IExecutorMethods::Method Method;
    Server::IExecutorMethodsPtr methods_;
};
	
} // namespace Client

} // namespac