#include "ProxyBase.h"


ProxyBase_IDirect3D9::ProxyBase_IDirect3D9(IDirect3D9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3D9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3D9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3D9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
    return pimpl_->RegisterSoftwareDevice(pInitializeFunction);
}

UINT ProxyBase_IDirect3D9::GetAdapterCount()
{
    return pimpl_->GetAdapterCount();
}

HRESULT ProxyBase_IDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    return pimpl_->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT ProxyBase_IDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    return pimpl_->GetAdapterModeCount(Adapter, Format);
}

HRESULT ProxyBase_IDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
    return pimpl_->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

HRESULT ProxyBase_IDirect3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
    return pimpl_->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT ProxyBase_IDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
    return pimpl_->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
}

HRESULT ProxyBase_IDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    return pimpl_->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT ProxyBase_IDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
    return pimpl_->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT ProxyBase_IDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    return pimpl_->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT ProxyBase_IDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    return pimpl_->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT ProxyBase_IDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
    return pimpl_->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR ProxyBase_IDirect3D9::GetAdapterMonitor(UINT Adapter)
{
    return pimpl_->GetAdapterMonitor(Adapter);
}

HRESULT ProxyBase_IDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    return pimpl_->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
}


