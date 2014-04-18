#include "stdafx.h"
#include "D3D.h"
#include "Device.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

ProxyImplPtr ProxyImpl::create(IBasePtr pimpl)
{
    return ProxyImplPtr(new ProxyImpl(pimpl));
}

ProxyImpl::ProxyImpl(IBasePtr pimpl)
    : ProxyBase(pimpl)
{

}

ULONG ProxyImpl::Release() 
{
    auto refcount = ProxyBase::Release();
    if (refcount == 0)
        detach_signal_();

    return refcount;
}

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
