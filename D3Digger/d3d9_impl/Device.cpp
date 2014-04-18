#include "stdafx.h"
#include "D3D.h"
#include "Device.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

ProxyImplPtr ProxyImpl::create(D3D::ProxyImplPtr parent, IBasePtr pimpl)
{
    return ProxyImplPtr(new ProxyImpl(parent, pimpl));
}

ProxyImpl::ProxyImpl(D3D::ProxyImplPtr parent, IBasePtr pimpl)
    : HierElem(std::dynamic_pointer_cast<HierElem>(parent))
    , ProxyBase(pimpl)
{

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
