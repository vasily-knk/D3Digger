#include "stdafx.h"
#include "Texture.h"

namespace D3Digger
{
namespace D3D9
{
namespace Texture
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

ProxyImplPtr ProxyImpl::getShared()
{
    return shared_from_this();
}


} // namespace Texture

} // namespace D3D9

} // namespace D3Digger
