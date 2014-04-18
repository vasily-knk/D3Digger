#include "stdafx.h"
#include "D3D.h"
#include "Device.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

ProxyImplPtr createProxy(D3D::ProxyImplPtr parent, IBasePtr pimpl)
{

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
}

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
