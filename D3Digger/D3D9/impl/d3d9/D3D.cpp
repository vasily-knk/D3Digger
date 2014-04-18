#include "stdafx.h"
#include "D3D.h"
#include "Device.h"

namespace D3Digger
{
namespace D3D9
{
namespace D3D
{

ProxyImplPtr ProxyImpl::create(IBasePtr pimpl)
{
    ProxyImplPtr p(new ProxyImpl(pimpl));
    p->init();
    return p;
}

ProxyImpl::ProxyImpl(IBasePtr pimpl)
    : HierElemAux(HierElemPtr())
    , ProxyBase(pimpl)
{
    
}

void ProxyImpl::init()
{
    HierElemAux::setParent(HierElem::shared_from_this());
}

ULONG ProxyImpl::Release() 
{
    auto refcount = ProxyBase::Release();
    if (refcount == 0)
        detach();
    return refcount;
}

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
