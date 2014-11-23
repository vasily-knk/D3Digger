
#include "stdafx.h"
#include "ProxyBase.h"
namespace D3D9
{
namespace Client
{
ProxyBase<IDirect3D9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3D9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3D9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3D9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3D9>::RegisterSoftwareDevice(void* pInitializeFunction)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::RegisterSoftwareDevice), inBytes);
    
    return D3D_OK;
}

UINT ProxyBase<IDirect3D9>::GetAdapterCount()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::GetAdapterCount), inBytes);
    
    bytes::read_proc rp(outBytes);
    UINT ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3D9>::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(Flags);
    wp(ptr2opt(pIdentifier));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::GetAdapterIdentifier), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pIdentifier) rp(*pIdentifier);
    return ret;
}

UINT ProxyBase<IDirect3D9>::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(Format);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::GetAdapterModeCount), inBytes);
    
    bytes::read_proc rp(outBytes);
    UINT ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3D9>::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(Format);
    wp(Mode);
    wp(ptr2opt(pMode));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::EnumAdapterModes), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pMode) rp(*pMode);
    return ret;
}

HRESULT ProxyBase<IDirect3D9>::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(ptr2opt(pMode));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::GetAdapterDisplayMode), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pMode) rp(*pMode);
    return ret;
}

HRESULT ProxyBase<IDirect3D9>::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DevType);
    wp(AdapterFormat);
    wp(BackBufferFormat);
    wp(bWindowed);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::CheckDeviceType), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3D9>::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DeviceType);
    wp(AdapterFormat);
    wp(Usage);
    wp(RType);
    wp(CheckFormat);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::CheckDeviceFormat), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3D9>::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DeviceType);
    wp(SurfaceFormat);
    wp(Windowed);
    wp(MultiSampleType);
    wp(ptr2opt(pQualityLevels));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::CheckDeviceMultiSampleType), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pQualityLevels) rp(*pQualityLevels);
    return ret;
}

HRESULT ProxyBase<IDirect3D9>::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DeviceType);
    wp(AdapterFormat);
    wp(RenderTargetFormat);
    wp(DepthStencilFormat);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::CheckDepthStencilMatch), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3D9>::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DeviceType);
    wp(SourceFormat);
    wp(TargetFormat);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::CheckDeviceFormatConversion), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3D9>::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DeviceType);
    wp(ptr2opt(pCaps));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::GetDeviceCaps), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pCaps) rp(*pCaps);
    return ret;
}

HMONITOR ProxyBase<IDirect3D9>::GetAdapterMonitor(UINT Adapter)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::GetAdapterMonitor), inBytes);
    
    bytes::read_proc rp(outBytes);
    HMONITOR ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3D9>::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Adapter);
    wp(DeviceType);
    wp(hFocusWindow);
    wp(BehaviorFlags);
    wp(ptr2opt(pPresentationParameters));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3D9, Methods_IDirect3D9::CreateDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pPresentationParameters) rp(*pPresentationParameters);
    *ppReturnedDeviceInterface = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

ProxyBase<IDirect3DDevice9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DDevice9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DDevice9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DDevice9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DDevice9>::TestCooperativeLevel()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::TestCooperativeLevel), inBytes);
    
    return D3D_OK;
}

UINT ProxyBase<IDirect3DDevice9>::GetAvailableTextureMem()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetAvailableTextureMem), inBytes);
    
    bytes::read_proc rp(outBytes);
    UINT ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::EvictManagedResources()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::EvictManagedResources), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetDirect3D(IDirect3D9** ppD3D9)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetDirect3D), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppD3D9 = getGlobal().proxyMap().getById<IDirect3D9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetDeviceCaps(D3DCAPS9* pCaps)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pCaps));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetDeviceCaps), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pCaps) rp(*pCaps);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    wp(ptr2opt(pMode));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetDisplayMode), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pMode) rp(*pMode);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pParameters));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetCreationParameters), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pParameters) rp(*pParameters);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(XHotSpot);
    wp(YHotSpot);
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pCursorBitmap)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetCursorProperties), inBytes);
    
    return D3D_OK;
}

void ProxyBase<IDirect3DDevice9>::SetCursorPosition(int X, int Y, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(X);
    wp(Y);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetCursorPosition), inBytes);
}

BOOL ProxyBase<IDirect3DDevice9>::ShowCursor(BOOL bShow)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(bShow);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::ShowCursor), inBytes);
    
    bytes::read_proc rp(outBytes);
    BOOL ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pPresentationParameters));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateAdditionalSwapChain), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pPresentationParameters) rp(*pPresentationParameters);
    *pSwapChain = getGlobal().proxyMap().getById<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetSwapChain), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *pSwapChain = getGlobal().proxyMap().getById<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    return ret;
}

UINT ProxyBase<IDirect3DDevice9>::GetNumberOfSwapChains()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetNumberOfSwapChains), inBytes);
    
    bytes::read_proc rp(outBytes);
    UINT ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pPresentationParameters));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Reset), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pPresentationParameters) rp(*pPresentationParameters);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pSourceRect));
    wp(ptr2opt(pDestRect));
    wp(hDestWindowOverride);
    wp(ptr2opt(pDirtyRegion));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Present), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    wp(iBackBuffer);
    wp(Type);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetBackBuffer), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppBackBuffer = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    wp(ptr2opt(pRasterStatus));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetRasterStatus), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pRasterStatus) rp(*pRasterStatus);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetDialogBoxMode(BOOL bEnableDialogs)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(bEnableDialogs);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetDialogBoxMode), inBytes);
    
    return D3D_OK;
}

void ProxyBase<IDirect3DDevice9>::SetGammaRamp(UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP* pRamp)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    wp(Flags);
    wp(ptr2opt(pRamp));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetGammaRamp), inBytes);
}

void ProxyBase<IDirect3DDevice9>::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    wp(ptr2opt(pRamp));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetGammaRamp), inBytes);
    
    bytes::read_proc rp(outBytes);
    if (pRamp) rp(*pRamp);
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Levels);
    wp(Usage);
    wp(Format);
    wp(Pool);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppTexture = getGlobal().proxyMap().getById<IDirect3DTexture9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Depth);
    wp(Levels);
    wp(Usage);
    wp(Format);
    wp(Pool);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVolumeTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppVolumeTexture = getGlobal().proxyMap().getById<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(EdgeLength);
    wp(Levels);
    wp(Usage);
    wp(Format);
    wp(Pool);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateCubeTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppCubeTexture = getGlobal().proxyMap().getById<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Length);
    wp(Usage);
    wp(FVF);
    wp(Pool);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVertexBuffer), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppVertexBuffer = getGlobal().proxyMap().getById<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Length);
    wp(Usage);
    wp(Format);
    wp(Pool);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateIndexBuffer), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppIndexBuffer = getGlobal().proxyMap().getById<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Format);
    wp(MultiSample);
    wp(MultisampleQuality);
    wp(Lockable);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateRenderTarget), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Format);
    wp(MultiSample);
    wp(MultisampleQuality);
    wp(Discard);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateDepthStencilSurface), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::UpdateSurface(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, const POINT* pDestPoint)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pSourceSurface)->getId());
    wp(ptr2opt(pSourceRect));
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pDestinationSurface)->getId());
    wp(ptr2opt(pDestPoint));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::UpdateSurface), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DBaseTexture9>*>(pSourceTexture)->getId());
    wp(dynamic_cast<IProxy<IDirect3DBaseTexture9>*>(pDestinationTexture)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::UpdateTexture), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pRenderTarget)->getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pDestSurface)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetRenderTargetData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iSwapChain);
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pDestSurface)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetFrontBufferData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::StretchRect(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestSurface, const RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pSourceSurface)->getId());
    wp(ptr2opt(pSourceRect));
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pDestSurface)->getId());
    wp(ptr2opt(pDestRect));
    wp(Filter);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::StretchRect), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::ColorFill(IDirect3DSurface9* pSurface, const RECT* pRect, D3DCOLOR color)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pSurface)->getId());
    wp(ptr2opt(pRect));
    wp(color);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::ColorFill), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Format);
    wp(Pool);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateOffscreenPlainSurface), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(RenderTargetIndex);
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pRenderTarget)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetRenderTarget), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(RenderTargetIndex);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetRenderTarget), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppRenderTarget = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pNewZStencil)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetDepthStencilSurface), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetDepthStencilSurface), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppZStencilSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::BeginScene()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::BeginScene), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::EndScene()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::EndScene), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::Clear(DWORD Count, const D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Count);
    wp(ptr2opt(pRects));
    wp(Flags);
    wp(Color);
    wp(Z);
    wp(Stencil);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Clear), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(State);
    wp(ptr2opt(pMatrix));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetTransform), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(State);
    wp(ptr2opt(pMatrix));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetTransform), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pMatrix) rp(*pMatrix);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::MultiplyTransform(D3DTRANSFORMSTATETYPE transform, const D3DMATRIX* matrix)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(transform);
    wp(ptr2opt(matrix));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::MultiplyTransform), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetViewport(const D3DVIEWPORT9* pViewport)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pViewport));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetViewport), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetViewport(D3DVIEWPORT9* pViewport)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pViewport));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetViewport), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pViewport) rp(*pViewport);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetMaterial(const D3DMATERIAL9* pMaterial)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pMaterial));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetMaterial), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetMaterial(D3DMATERIAL9* pMaterial)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pMaterial));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetMaterial), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pMaterial) rp(*pMaterial);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetLight(DWORD Index, const D3DLIGHT9* pLight)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Index);
    wp(ptr2opt(pLight));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetLight), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetLight(DWORD Index, D3DLIGHT9* pLight)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Index);
    wp(ptr2opt(pLight));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetLight), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pLight) rp(*pLight);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::LightEnable(DWORD Index, BOOL Enable)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Index);
    wp(Enable);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::LightEnable), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Index);
    wp(ptr2opt(pEnable));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetLightEnable), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pEnable) rp(*pEnable);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetClipPlane(DWORD Index, const float* pPlane)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Index);
    wp(ptr2opt(pPlane));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetClipPlane), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetClipPlane(DWORD Index, float* pPlane)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Index);
    wp(ptr2opt(pPlane));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetClipPlane), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pPlane) rp(*pPlane);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(State);
    wp(Value);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetRenderState), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(State);
    wp(ptr2opt(pValue));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetRenderState), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pValue) rp(*pValue);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Type);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateStateBlock), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSB = getGlobal().proxyMap().getById<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::BeginStateBlock()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::BeginStateBlock), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::EndStateBlock), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSB = getGlobal().proxyMap().getById<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetClipStatus(const D3DCLIPSTATUS9* pClipStatus)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pClipStatus));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetClipStatus), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pClipStatus));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetClipStatus), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pClipStatus) rp(*pClipStatus);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Stage);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppTexture = getGlobal().proxyMap().getById<IDirect3DBaseTexture9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Stage);
    wp(dynamic_cast<IProxy<IDirect3DBaseTexture9>*>(pTexture)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetTexture), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Stage);
    wp(Type);
    wp(ptr2opt(pValue));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetTextureStageState), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pValue) rp(*pValue);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Stage);
    wp(Type);
    wp(Value);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetTextureStageState), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Sampler);
    wp(Type);
    wp(ptr2opt(pValue));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetSamplerState), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pValue) rp(*pValue);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Sampler);
    wp(Type);
    wp(Value);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetSamplerState), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::ValidateDevice(DWORD* pNumPasses)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pNumPasses));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::ValidateDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pNumPasses) rp(*pNumPasses);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY* pEntries)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PaletteNumber);
    wp(ptr2opt(pEntries));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetPaletteEntries), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PaletteNumber);
    wp(ptr2opt(pEntries));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetPaletteEntries), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pEntries) rp(*pEntries);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetCurrentTexturePalette(UINT PaletteNumber)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PaletteNumber);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetCurrentTexturePalette), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetCurrentTexturePalette(UINT* PaletteNumber)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(PaletteNumber));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetCurrentTexturePalette), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (PaletteNumber) rp(*PaletteNumber);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetScissorRect(const RECT* pRect)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pRect));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetScissorRect), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetScissorRect(RECT* pRect)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pRect));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetScissorRect), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pRect) rp(*pRect);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(bSoftware);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetSoftwareVertexProcessing), inBytes);
    
    return D3D_OK;
}

BOOL ProxyBase<IDirect3DDevice9>::GetSoftwareVertexProcessing()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetSoftwareVertexProcessing), inBytes);
    
    bytes::read_proc rp(outBytes);
    BOOL ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetNPatchMode(float nSegments)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(nSegments);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetNPatchMode), inBytes);
    
    return D3D_OK;
}

float ProxyBase<IDirect3DDevice9>::GetNPatchMode()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetNPatchMode), inBytes);
    
    bytes::read_proc rp(outBytes);
    float ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PrimitiveType);
    wp(StartVertex);
    wp(PrimitiveCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DrawPrimitive), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PrimitiveType);
    wp(BaseVertexIndex);
    wp(MinVertexIndex);
    wp(NumVertices);
    wp(startIndex);
    wp(primCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DrawIndexedPrimitive), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PrimitiveType);
    wp(PrimitiveCount);
    wp(VertexStreamZeroStride);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DrawPrimitiveUP), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, const void* pIndexData, D3DFORMAT IndexDataFormat, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PrimitiveType);
    wp(MinVertexIndex);
    wp(NumVertices);
    wp(PrimitiveCount);
    wp(IndexDataFormat);
    wp(VertexStreamZeroStride);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DrawIndexedPrimitiveUP), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(SrcStartIndex);
    wp(DestIndex);
    wp(VertexCount);
    wp(dynamic_cast<IProxy<IDirect3DVertexBuffer9>*>(pDestBuffer)->getId());
    wp(dynamic_cast<IProxy<IDirect3DVertexDeclaration9>*>(pVertexDecl)->getId());
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::ProcessVertices), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pVertexElements));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVertexDeclaration), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDecl = getGlobal().proxyMap().getById<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DVertexDeclaration9>*>(pDecl)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetVertexDeclaration), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetVertexDeclaration), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDecl = getGlobal().proxyMap().getById<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetFVF(DWORD FVF)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FVF);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetFVF), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetFVF(DWORD* pFVF)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pFVF));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetFVF), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pFVF) rp(*pFVF);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexShader(const DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pFunction));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVertexShader), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppShader = getGlobal().proxyMap().getById<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShader(IDirect3DVertexShader9* pShader)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DVertexShader9>*>(pShader)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetVertexShader), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetVertexShader), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppShader = getGlobal().proxyMap().getById<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4fCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetVertexShaderConstantF), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4fCount);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetVertexShaderConstantF), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pConstantData) rp(*pConstantData);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4iCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetVertexShaderConstantI), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4iCount);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetVertexShaderConstantI), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pConstantData) rp(*pConstantData);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(BoolCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetVertexShaderConstantB), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(BoolCount);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetVertexShaderConstantB), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pConstantData) rp(*pConstantData);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StreamNumber);
    wp(dynamic_cast<IProxy<IDirect3DVertexBuffer9>*>(pStreamData)->getId());
    wp(OffsetInBytes);
    wp(Stride);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetStreamSource), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StreamNumber);
    wp(ptr2opt(pOffsetInBytes));
    wp(ptr2opt(pStride));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetStreamSource), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppStreamData = getGlobal().proxyMap().getById<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    if (pOffsetInBytes) rp(*pOffsetInBytes);
    if (pStride) rp(*pStride);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetStreamSourceFreq(UINT StreamNumber, UINT Setting)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StreamNumber);
    wp(Setting);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetStreamSourceFreq), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StreamNumber);
    wp(ptr2opt(pSetting));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetStreamSourceFreq), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSetting) rp(*pSetting);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DIndexBuffer9>*>(pIndexData)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetIndices), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetIndices), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppIndexData = getGlobal().proxyMap().getById<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreatePixelShader(const DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pFunction));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreatePixelShader), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppShader = getGlobal().proxyMap().getById<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShader(IDirect3DPixelShader9* pShader)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DPixelShader9>*>(pShader)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetPixelShader), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetPixelShader), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppShader = getGlobal().proxyMap().getById<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4fCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetPixelShaderConstantF), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4fCount);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetPixelShaderConstantF), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pConstantData) rp(*pConstantData);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4iCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetPixelShaderConstantI), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(Vector4iCount);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetPixelShaderConstantI), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pConstantData) rp(*pConstantData);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(BoolCount);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::SetPixelShaderConstantB), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(StartRegister);
    wp(ptr2opt(pConstantData));
    wp(BoolCount);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::GetPixelShaderConstantB), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pConstantData) rp(*pConstantData);
    return ret;
}

HRESULT ProxyBase<IDirect3DDevice9>::DrawRectPatch(UINT Handle, const float* pNumSegs, const D3DRECTPATCH_INFO* pRectPatchInfo)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Handle);
    wp(ptr2opt(pNumSegs));
    wp(ptr2opt(pRectPatchInfo));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DrawRectPatch), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::DrawTriPatch(UINT Handle, const float* pNumSegs, const D3DTRIPATCH_INFO* pTriPatchInfo)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Handle);
    wp(ptr2opt(pNumSegs));
    wp(ptr2opt(pTriPatchInfo));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DrawTriPatch), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::DeletePatch(UINT Handle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Handle);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::DeletePatch), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DDevice9>::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Type);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateQuery), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    
    ProxyId result_id;
    rp(result_id);
    
    if (ppQuery) *ppQuery = getGlobal().proxyMap().getById<IDirect3DQuery9>(result_id);
    
    
    return ret;
}

ProxyBase<IDirect3DStateBlock9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DStateBlock9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DStateBlock9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DStateBlock9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DStateBlock9, Methods_IDirect3DStateBlock9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DStateBlock9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DStateBlock9, Methods_IDirect3DStateBlock9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DStateBlock9>::Capture()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DStateBlock9, Methods_IDirect3DStateBlock9::Capture), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DStateBlock9>::Apply()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DStateBlock9, Methods_IDirect3DStateBlock9::Apply), inBytes);
    
    return D3D_OK;
}

ProxyBase<IDirect3DSwapChain9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DSwapChain9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DSwapChain9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DSwapChain9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion, DWORD dwFlags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pSourceRect));
    wp(ptr2opt(pDestRect));
    wp(hDestWindowOverride);
    wp(ptr2opt(pDirtyRegion));
    wp(dwFlags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::Present), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::GetFrontBufferData(IDirect3DSurface9* pDestSurface)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dynamic_cast<IProxy<IDirect3DSurface9>*>(pDestSurface)->getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::GetFrontBufferData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(iBackBuffer);
    wp(Type);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::GetBackBuffer), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppBackBuffer = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pRasterStatus));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::GetRasterStatus), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pRasterStatus) rp(*pRasterStatus);
    return ret;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pMode));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::GetDisplayMode), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pMode) rp(*pMode);
    return ret;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DSwapChain9>::GetPresentParameters(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pPresentationParameters));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSwapChain9, Methods_IDirect3DSwapChain9::GetPresentParameters), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pPresentationParameters) rp(*pPresentationParameters);
    return ret;
}

ProxyBase<IDirect3DVertexDeclaration9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DVertexDeclaration9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DVertexDeclaration9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DVertexDeclaration9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexDeclaration9, Methods_IDirect3DVertexDeclaration9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DVertexDeclaration9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexDeclaration9, Methods_IDirect3DVertexDeclaration9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DVertexDeclaration9>::GetDeclaration(D3DVERTEXELEMENT9* pElement, UINT* pNumElements)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pElement));
    wp(ptr2opt(pNumElements));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexDeclaration9, Methods_IDirect3DVertexDeclaration9::GetDeclaration), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pElement) rp(*pElement);
    if (pNumElements) rp(*pNumElements);
    return ret;
}

ProxyBase<IDirect3DVertexShader9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DVertexShader9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DVertexShader9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DVertexShader9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexShader9, Methods_IDirect3DVertexShader9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DVertexShader9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexShader9, Methods_IDirect3DVertexShader9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DVertexShader9>::GetFunction(void* pFunction, UINT* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexShader9, Methods_IDirect3DVertexShader9::GetFunction), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

ProxyBase<IDirect3DPixelShader9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DPixelShader9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DPixelShader9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DPixelShader9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DPixelShader9, Methods_IDirect3DPixelShader9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DPixelShader9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DPixelShader9, Methods_IDirect3DPixelShader9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DPixelShader9>::GetFunction(void* pFunction, UINT* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DPixelShader9, Methods_IDirect3DPixelShader9::GetFunction), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

ProxyBase<IDirect3DTexture9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DTexture9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DTexture9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DTexture9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

DWORD ProxyBase<IDirect3DTexture9>::SetPriority(DWORD PriorityNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PriorityNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::SetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DTexture9>::GetPriority()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DTexture9>::PreLoad()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::PreLoad), inBytes);
}

D3DRESOURCETYPE ProxyBase<IDirect3DTexture9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DRESOURCETYPE ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DTexture9>::SetLOD(DWORD LODNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(LODNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::SetLOD), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DTexture9>::GetLOD()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetLOD), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DTexture9>::GetLevelCount()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetLevelCount), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FilterType);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::SetAutoGenFilterType), inBytes);
    
    return D3D_OK;
}

D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DTexture9>::GetAutoGenFilterType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetAutoGenFilterType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DTEXTUREFILTERTYPE ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DTexture9>::GenerateMipSubLevels()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GenerateMipSubLevels), inBytes);
}

HRESULT ProxyBase<IDirect3DTexture9>::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetLevelDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

HRESULT ProxyBase<IDirect3DTexture9>::GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::GetSurfaceLevel), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSurfaceLevel = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());

    return ret;
}

HRESULT ProxyBase<IDirect3DTexture9>::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    wp(ptr2opt(pLockedRect));
    wp(ptr2opt(pRect));
    wp(Flags);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::LockRect), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pLockedRect) rp(*pLockedRect);
    return ret;
}

HRESULT ProxyBase<IDirect3DTexture9>::UnlockRect(UINT Level)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::UnlockRect), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DTexture9>::AddDirtyRect(const RECT* pDirtyRect)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pDirtyRect));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DTexture9, Methods_IDirect3DTexture9::AddDirtyRect), inBytes);
    
    return D3D_OK;
}

ProxyBase<IDirect3DVolumeTexture9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DVolumeTexture9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DVolumeTexture9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

DWORD ProxyBase<IDirect3DVolumeTexture9>::SetPriority(DWORD PriorityNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PriorityNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::SetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DVolumeTexture9>::GetPriority()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DVolumeTexture9>::PreLoad()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::PreLoad), inBytes);
}

D3DRESOURCETYPE ProxyBase<IDirect3DVolumeTexture9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DRESOURCETYPE ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DVolumeTexture9>::SetLOD(DWORD LODNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(LODNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::SetLOD), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DVolumeTexture9>::GetLOD()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetLOD), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DVolumeTexture9>::GetLevelCount()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetLevelCount), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FilterType);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::SetAutoGenFilterType), inBytes);
    
    return D3D_OK;
}

D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DVolumeTexture9>::GetAutoGenFilterType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetAutoGenFilterType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DTEXTUREFILTERTYPE ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DVolumeTexture9>::GenerateMipSubLevels()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GenerateMipSubLevels), inBytes);
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetLevelDesc(UINT Level, D3DVOLUME_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetLevelDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetVolumeLevel(UINT Level, IDirect3DVolume9** ppVolumeLevel)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::GetVolumeLevel), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppVolumeLevel = getGlobal().proxyMap().getById<IDirect3DVolume9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::LockBox(UINT Level, D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    wp(ptr2opt(pLockedVolume));
    wp(ptr2opt(pBox));
    wp(Flags);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::LockBox), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pLockedVolume) rp(*pLockedVolume);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::UnlockBox(UINT Level)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::UnlockBox), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVolumeTexture9>::AddDirtyBox(const D3DBOX* pDirtyBox)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pDirtyBox));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolumeTexture9, Methods_IDirect3DVolumeTexture9::AddDirtyBox), inBytes);
    
    return D3D_OK;
}

ProxyBase<IDirect3DCubeTexture9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DCubeTexture9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DCubeTexture9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

DWORD ProxyBase<IDirect3DCubeTexture9>::SetPriority(DWORD PriorityNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PriorityNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::SetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DCubeTexture9>::GetPriority()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DCubeTexture9>::PreLoad()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::PreLoad), inBytes);
}

D3DRESOURCETYPE ProxyBase<IDirect3DCubeTexture9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DRESOURCETYPE ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DCubeTexture9>::SetLOD(DWORD LODNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(LODNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::SetLOD), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DCubeTexture9>::GetLOD()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetLOD), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DCubeTexture9>::GetLevelCount()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetLevelCount), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FilterType);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::SetAutoGenFilterType), inBytes);
    
    return D3D_OK;
}

D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DCubeTexture9>::GetAutoGenFilterType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetAutoGenFilterType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DTEXTUREFILTERTYPE ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DCubeTexture9>::GenerateMipSubLevels()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GenerateMipSubLevels), inBytes);
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Level);
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetLevelDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9** ppCubeMapSurface)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FaceType);
    wp(Level);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::GetCubeMapSurface), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppCubeMapSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FaceType);
    wp(Level);
    wp(ptr2opt(pLockedRect));
    wp(ptr2opt(pRect));
    wp(Flags);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::LockRect), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pLockedRect) rp(*pLockedRect);
    return ret;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FaceType);
    wp(Level);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::UnlockRect), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DCubeTexture9>::AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT* pDirtyRect)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(FaceType);
    wp(ptr2opt(pDirtyRect));
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DCubeTexture9, Methods_IDirect3DCubeTexture9::AddDirtyRect), inBytes);
    
    return D3D_OK;
}

ProxyBase<IDirect3DVertexBuffer9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DVertexBuffer9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DVertexBuffer9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

DWORD ProxyBase<IDirect3DVertexBuffer9>::SetPriority(DWORD PriorityNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PriorityNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::SetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DVertexBuffer9>::GetPriority()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::GetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DVertexBuffer9>::PreLoad()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::PreLoad), inBytes);
}

D3DRESOURCETYPE ProxyBase<IDirect3DVertexBuffer9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DRESOURCETYPE ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(OffsetToLock);
    wp(SizeToLock);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::Lock), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::Unlock()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::Unlock), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetDesc(D3DVERTEXBUFFER_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::GetDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

ProxyBase<IDirect3DIndexBuffer9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DIndexBuffer9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DIndexBuffer9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

DWORD ProxyBase<IDirect3DIndexBuffer9>::SetPriority(DWORD PriorityNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PriorityNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::SetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DIndexBuffer9>::GetPriority()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::GetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DIndexBuffer9>::PreLoad()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::PreLoad), inBytes);
}

D3DRESOURCETYPE ProxyBase<IDirect3DIndexBuffer9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DRESOURCETYPE ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(OffsetToLock);
    wp(SizeToLock);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::Lock), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::Unlock()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::Unlock), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetDesc(D3DINDEXBUFFER_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::GetDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

ProxyBase<IDirect3DSurface9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DSurface9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DSurface9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DSurface9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DSurface9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DSurface9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DSurface9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DSurface9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

DWORD ProxyBase<IDirect3DSurface9>::SetPriority(DWORD PriorityNew)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(PriorityNew);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::SetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DSurface9>::GetPriority()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetPriority), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

void ProxyBase<IDirect3DSurface9>::PreLoad()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::PreLoad), inBytes);
}

D3DRESOURCETYPE ProxyBase<IDirect3DSurface9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DRESOURCETYPE ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DSurface9>::GetContainer(REFIID riid, void** ppContainer)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(riid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetContainer), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DSurface9>::GetDesc(D3DSURFACE_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

HRESULT ProxyBase<IDirect3DSurface9>::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pLockedRect));
    wp(ptr2opt(pRect));
    wp(Flags);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::LockRect), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pLockedRect) rp(*pLockedRect);
    return ret;
}

HRESULT ProxyBase<IDirect3DSurface9>::UnlockRect()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::UnlockRect), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DSurface9>::GetDC(HDC* phdc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(phdc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::GetDC), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (phdc) rp(*phdc);
    return ret;
}

HRESULT ProxyBase<IDirect3DSurface9>::ReleaseDC(HDC hdc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(hdc);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::ReleaseDC), inBytes);
    
    return D3D_OK;
}

ProxyBase<IDirect3DVolume9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DVolume9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DVolume9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DVolume9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DVolume9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT ProxyBase<IDirect3DVolume9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(SizeOfData);
    wp(Flags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::SetPrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVolume9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    wp(ptr2opt(pSizeOfData));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::GetPrivateData), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pSizeOfData) rp(*pSizeOfData);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolume9>::FreePrivateData(REFGUID refguid)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(refguid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::FreePrivateData), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVolume9>::GetContainer(REFIID riid, void** ppContainer)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(riid);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::GetContainer), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DVolume9>::GetDesc(D3DVOLUME_DESC* pDesc)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pDesc));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::GetDesc), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pDesc) rp(*pDesc);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolume9>::LockBox(D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(ptr2opt(pLockedVolume));
    wp(ptr2opt(pBox));
    wp(Flags);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::LockBox), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    if (pLockedVolume) rp(*pLockedVolume);
    return ret;
}

HRESULT ProxyBase<IDirect3DVolume9>::UnlockBox()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVolume9, Methods_IDirect3DVolume9::UnlockBox), inBytes);
    
    return D3D_OK;
}

ProxyBase<IDirect3DQuery9>::ProxyBase(ProxyId id)
    : id_(id)
    , refcount_(1)
{
}

HRESULT ProxyBase<IDirect3DQuery9>::QueryInterface(REFIID riid, void** ppvObj)
{
    if (!ppvObj)
        return E_POINTER;
    else
    {
        *ppvObj = nullptr;
        return E_NOINTERFACE;
    }
}

ULONG ProxyBase<IDirect3DQuery9>::AddRef()
{
    assert(refcount_ > 0);
    ++refcount_;
    return refcount_;
}

ULONG ProxyBase<IDirect3DQuery9>::Release()
{
    --refcount_;
    assert(refcount_ >= 0);
    if (refcount_ == 0)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::Release), inBytes);
        emitDeleted();
        delete this;
        return 0;
    } else
        return refcount_;
}

HRESULT ProxyBase<IDirect3DQuery9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::GetDevice), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDevice = getGlobal().proxyMap().getById<IDirect3DDevice9>(rp.operator()<ProxyId>());
    return ret;
}

D3DQUERYTYPE ProxyBase<IDirect3DQuery9>::GetType()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::GetType), inBytes);
    
    bytes::read_proc rp(outBytes);
    D3DQUERYTYPE ret; rp(ret);
    return ret;
}

DWORD ProxyBase<IDirect3DQuery9>::GetDataSize()
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::GetDataSize), inBytes);
    
    bytes::read_proc rp(outBytes);
    DWORD ret; rp(ret);
    return ret;
}

HRESULT ProxyBase<IDirect3DQuery9>::Issue(DWORD dwIssueFlags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dwIssueFlags);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::Issue), inBytes);
    
    return D3D_OK;
}

HRESULT ProxyBase<IDirect3DQuery9>::GetData(void* pData, DWORD dwSize, DWORD dwGetDataFlags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dwSize);
    wp(dwGetDataFlags);
    
    getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::GetData), inBytes);
    
    return D3D_OK;
}

} // namespace D3D9

} // namespace Client

