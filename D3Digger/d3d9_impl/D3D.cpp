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

HRESULT ProxyImpl::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    auto res = ProxyBase::CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

    if (ppReturnedDeviceInterface && SUCCEEDED(res) && *ppReturnedDeviceInterface)
    {
        Device::ProxyImplPtr child = Device::ProxyImpl::create(*ppReturnedDeviceInterface);
        keeper_.addChild(child);
        *ppReturnedDeviceInterface = child.get();
    }

    return res;
}


} // namespace Device

} // namespace D3D9

} // namespace D3Digger
