#pragma once

#include "d3d9/Client/IExecutor.h"
#include "d3d9/Server/IProcMethods.h"
#include "common/time_counter.h"

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
    BytesPtr run(MethodId const &id, BytesPtr args);

private:
    void updateSyncs(MethodId const &id);
    void printSyncs();

private:
    typedef Server::IProcMethods::Method Method;
    Server::IExecutorMethodsPtr methods_;
    
    size_t numFrames_;
    std::map<MethodId, uint32_t> syncs_;
    time_counter tc_;
};
	
} // namespace Client

} // namespac