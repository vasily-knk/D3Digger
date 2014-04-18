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
    addChild(HierElem::shared_from_this());
}

ULONG ProxyImpl::Release() 
{
    auto refcount = ProxyBase::Release();
    if (refcount == 0)
        detach();
    return refcount;
}

HRESULT ProxyImpl::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    auto res = ProxyBase::CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
    if (ppReturnedDeviceInterface && SUCCEEDED(res) && *ppReturnedDeviceInterface)
    {
        auto shared_this = dynamic_pointer_cast<ProxyImpl>(shared_from_this());
        Device::ProxyImplPtr child = Device::ProxyImpl::create(shared_this, *ppReturnedDeviceInterface);
        addChild(child);
    }

    return res;
}


} // namespace Device

} // namespace D3D9

} // namespace D3Digger
