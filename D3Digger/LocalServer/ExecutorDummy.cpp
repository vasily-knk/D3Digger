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
    try
    {
        updateTraffic(id, srcArgs->size());
    
        BytesPtr dstArgs = bytes::make();
        Method method = methods_->getMethod(id);
        method.first(srcArgs, dstArgs);

        return dstArgs;
    }
    catch(std::exception const &e)
    {
        LogError(e.what());
        Verify(false);
    }
    catch(...)
    {
        LogError("Unknown exception");
        Verify(false); 
    }
}

void ExecutorDummy::runAsync(MethodId const &id, BytesPtr args) 
{
	runSync(id, args);
}

void ExecutorDummy::updateTraffic(MethodId const &id, size_t size)
{
    if (tc_.time().total_seconds() > 10)
    {
        sortTraffic();
        tc_.reset();
    }
    
    if (traffic_.count(id) == 0)
        traffic_.emplace(id, 0);

    traffic_.at(id) += size;
}

void ExecutorDummy::sortTraffic()
{
    typedef pair<string, uint64_t> Record;
    struct comp
    {
        bool operator()(Record const &a, Record const &b) const
        {
            return a.second > b.second;
        }
    };

    vector<Record> sorted;
    sorted.reserve(traffic_.size());
    for (auto &r : traffic_)
    {
        string str = methods_->getMethod(r.first).second;
        sorted.emplace_back(str, r.second);
        r.second = 0;
    }

    std::sort(sorted.begin(), sorted.end(), comp());

    size_t num = std::min<size_t>(10, sorted.size());
    LogTrace("Traffic stats: ");
    for (size_t i = 0; i < num; ++i)
        LogTrace(sorted[i].first << ": " << sorted[i].second / 1024 / 1024 << " mb.");
}

} // namespace Client

} // namespace D3D9