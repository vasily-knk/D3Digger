#include "stdafx.h"
#include "ExecutorDummy.h"

namespace D3D9
{
namespace Client
{
    
ExecutorDummy::ExecutorDummy()
    : methods_(Server::createProcMethods())
    , numFrames_(0)
{
}

ExecutorDummy::~ExecutorDummy()
{
}

BytesPtr ExecutorDummy::run(MethodId const& id, BytesPtr srcArgs) 
{
    try
    {
        //updateTraffic(id, srcArgs->size());

        if (id == makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Present))
            ++numFrames_;
    
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
    run(id, args);
}

BytesPtr ExecutorDummy::runSync(MethodId const &id, BytesPtr args) 
{
    updateSyncs(id);
	return run(id, args);
}

void ExecutorDummy::updateSyncs(MethodId const &id)
{
	if (syncs_.count(id) == 0)
        syncs_.emplace(id, 0);

    ++syncs_.at(id);

    if (tc_.time().total_seconds() > 10)
    {
        printSyncs();
        tc_.reset();
    }

}

void ExecutorDummy::printSyncs()
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
    sorted.reserve(syncs_.size());
    for (auto &r : syncs_)
    {
        string str = methods_->getMethod(r.first).second;
        sorted.emplace_back(str, r.second);
    }

    std::sort(sorted.begin(), sorted.end(), comp());

    size_t num = std::min<size_t>(10, sorted.size());
    LogTrace("sync stats: " << numFrames_ << " frames");
    for (size_t i = 0; i < num; ++i)
        LogTrace(sorted[i].first << ": " << sorted[i].second);

    syncs_.clear();
    numFrames_ = 0;
}

} // namespace Client

} // namespace D3D9