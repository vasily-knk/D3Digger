#include "stdafx.h"
#include "d3d9/Server/IProcMap.h"

namespace D3D9
{

namespace Server
{

struct ProcMapImpl
    : IProcMap
{
    ProcMapImpl();
    
    ProxyId getProxyID(IUnknown *ptr) override;
    IUnknown *getPtrImpl(ProxyId id) override;

private:
    ProxyId getNextProxyId();

private:
    typedef boost::bimap<boost::bimaps::unordered_set_of<ProxyId>, boost::bimaps::unordered_set_of<IUnknown*>> Bimap;

    Bimap bimap_;
    ProxyId nextProxyId_;
};

IProcMapPtr createProcMap()
{
    return make_shared<ProcMapImpl>();
}


ProcMapImpl::ProcMapImpl()
    : nextProxyId_(0)
{
}

ProxyId ProcMapImpl::getProxyID(IUnknown *ptr)
{
    if (bimap_.right.count(ptr) == 0)
        bimap_.insert(Bimap::value_type(getNextProxyId(), ptr));

    return bimap_.right.at(ptr);
}

IUnknown *ProcMapImpl::getPtrImpl(ProxyId id)
{
    return bimap_.left.at(id);
}

ProxyId ProcMapImpl::getNextProxyId()
{
    return nextProxyId_++;
}



} // namespace Server

} // namespace D3D9