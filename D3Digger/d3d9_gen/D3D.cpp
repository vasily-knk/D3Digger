#include "D3D.h"

namespace D3Digger
{
namespace D3D9
{
namespace D3D
{

ProxyBase::ProxyBase(IBasePtr pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase::Release()
{
    return pimpl_->Release();
}

HRESULT ProxyBase::RegisterSoftwareDevice(void* pInitializeFunction)
{
    return pimpl_->RegisterSoftwareDevice(pInitializeFunction);
}

UINT ProxyBase::GetAdapterCount()
{
    return pimpl_->GetAdapterCount();
}

HRESULT ProxyBase::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    return pimpl_->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT ProxyBase::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    return pimpl_->GetAdapterModeCount(Adapter, Format);
}

HRESULT ProxyBase::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
    return pimpl_->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

HRESULT ProxyBase::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
    return pimpl_->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT ProxyBase::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
    return pimpl_->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
}

HRESULT ProxyBase::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    return pimpl_->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT ProxyBase::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
    return pimpl_->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT ProxyBase::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    return pimpl_->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT ProxyBase::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    return pimpl_->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT ProxyBase::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
    return pimpl_->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR ProxyBase::GetAdapterMonitor(UINT Adapter)
{
    return pimpl_->GetAdapterMonitor(Adapter);
}

HRESULT ProxyBase::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    return pimpl_->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
}

} // namespace D3Digger

} // namespace D3D9

} // namespace D3D


