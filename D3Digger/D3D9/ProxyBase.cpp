#include "stdafx.h"
#include "ProxyBase.h"
            
ProxyBase<IDirect3D9>::ProxyBase(IDirect3D9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3D9 *ProxyBase<IDirect3D9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3D9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3D9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3D9>::AddRef()
{
    logMethod("IDirect3D9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3D9>::Release()
{
    logMethod("IDirect3D9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::RegisterSoftwareDevice(void* pInitializeFunction)
{
    logMethod("IDirect3D9", "RegisterSoftwareDevice");
   
   auto res = pimpl_->RegisterSoftwareDevice(pInitializeFunction);
   
   return checkReturn(res, "IDirect3D9", "RegisterSoftwareDevice");
                    
}
                
UINT ProxyBase<IDirect3D9>::GetAdapterCount()
{
    logMethod("IDirect3D9", "GetAdapterCount");
   
   auto res = pimpl_->GetAdapterCount();
   
   return checkReturn(res, "IDirect3D9", "GetAdapterCount");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    logMethod("IDirect3D9", "GetAdapterIdentifier");
   
   auto res = pimpl_->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
   
   return checkReturn(res, "IDirect3D9", "GetAdapterIdentifier");
                    
}
                
UINT ProxyBase<IDirect3D9>::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    logMethod("IDirect3D9", "GetAdapterModeCount");
   
   auto res = pimpl_->GetAdapterModeCount(Adapter, Format);
   
   return checkReturn(res, "IDirect3D9", "GetAdapterModeCount");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
    logMethod("IDirect3D9", "EnumAdapterModes");
   
   auto res = pimpl_->EnumAdapterModes(Adapter, Format, Mode, pMode);
   
   return checkReturn(res, "IDirect3D9", "EnumAdapterModes");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
    logMethod("IDirect3D9", "GetAdapterDisplayMode");
   
   auto res = pimpl_->GetAdapterDisplayMode(Adapter, pMode);
   
   return checkReturn(res, "IDirect3D9", "GetAdapterDisplayMode");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
    logMethod("IDirect3D9", "CheckDeviceType");
   
   auto res = pimpl_->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
   
   return checkReturn(res, "IDirect3D9", "CheckDeviceType");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    logMethod("IDirect3D9", "CheckDeviceFormat");
   
   auto res = pimpl_->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
   
   return checkReturn(res, "IDirect3D9", "CheckDeviceFormat");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
    logMethod("IDirect3D9", "CheckDeviceMultiSampleType");
   
   auto res = pimpl_->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
   
   return checkReturn(res, "IDirect3D9", "CheckDeviceMultiSampleType");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    logMethod("IDirect3D9", "CheckDepthStencilMatch");
   
   auto res = pimpl_->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
   
   return checkReturn(res, "IDirect3D9", "CheckDepthStencilMatch");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    logMethod("IDirect3D9", "CheckDeviceFormatConversion");
   
   auto res = pimpl_->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
   
   return checkReturn(res, "IDirect3D9", "CheckDeviceFormatConversion");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
    logMethod("IDirect3D9", "GetDeviceCaps");
   
   auto res = pimpl_->GetDeviceCaps(Adapter, DeviceType, pCaps);
   
   return checkReturn(res, "IDirect3D9", "GetDeviceCaps");
                    
}
                
HMONITOR ProxyBase<IDirect3D9>::GetAdapterMonitor(UINT Adapter)
{
    logMethod("IDirect3D9", "GetAdapterMonitor");
   
   auto res = pimpl_->GetAdapterMonitor(Adapter);
   
   return checkReturn(res, "IDirect3D9", "GetAdapterMonitor");
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    logMethod("IDirect3D9", "CreateDevice");
   
   auto res = pimpl_->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
       if (SUCCEEDED(res))
    {
        if (ppReturnedDeviceInterface) {*ppReturnedDeviceInterface = wrapProxy<IDirect3DDevice9>(*ppReturnedDeviceInterface).get();}
    }
                        
   return checkReturn(res, "IDirect3D9", "CreateDevice");
                    
}
                
ProxyBase<IDirect3DDevice9>::ProxyBase(IDirect3DDevice9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DDevice9 *ProxyBase<IDirect3DDevice9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DDevice9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DDevice9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DDevice9>::AddRef()
{
    logMethod("IDirect3DDevice9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DDevice9>::Release()
{
    logMethod("IDirect3DDevice9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::TestCooperativeLevel()
{
    logMethod("IDirect3DDevice9", "TestCooperativeLevel");
   
   auto res = pimpl_->TestCooperativeLevel();
   
   return checkReturn(res, "IDirect3DDevice9", "TestCooperativeLevel");
                    
}
                
UINT ProxyBase<IDirect3DDevice9>::GetAvailableTextureMem()
{
    logMethod("IDirect3DDevice9", "GetAvailableTextureMem");
   
   auto res = pimpl_->GetAvailableTextureMem();
   
   return checkReturn(res, "IDirect3DDevice9", "GetAvailableTextureMem");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::EvictManagedResources()
{
    logMethod("IDirect3DDevice9", "EvictManagedResources");
   
   auto res = pimpl_->EvictManagedResources();
   
   return checkReturn(res, "IDirect3DDevice9", "EvictManagedResources");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDirect3D(IDirect3D9** ppD3D9)
{
    logMethod("IDirect3DDevice9", "GetDirect3D");
   
   auto res = pimpl_->GetDirect3D(ppD3D9);
       if (SUCCEEDED(res))
    {
        if (ppD3D9) {*ppD3D9 = wrapProxy<IDirect3D9>(*ppD3D9).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetDirect3D");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDeviceCaps(D3DCAPS9* pCaps)
{
    logMethod("IDirect3DDevice9", "GetDeviceCaps");
   
   auto res = pimpl_->GetDeviceCaps(pCaps);
   
   return checkReturn(res, "IDirect3DDevice9", "GetDeviceCaps");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
    logMethod("IDirect3DDevice9", "GetDisplayMode");
   
   auto res = pimpl_->GetDisplayMode(iSwapChain, pMode);
   
   return checkReturn(res, "IDirect3DDevice9", "GetDisplayMode");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
    logMethod("IDirect3DDevice9", "GetCreationParameters");
   
   auto res = pimpl_->GetCreationParameters(pParameters);
   
   return checkReturn(res, "IDirect3DDevice9", "GetCreationParameters");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
    logMethod("IDirect3DDevice9", "SetCursorProperties");
   if (pCursorBitmap) {pCursorBitmap = unwrapProxy<IDirect3DSurface9>(pCursorBitmap);}
   auto res = pimpl_->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
   
   return checkReturn(res, "IDirect3DDevice9", "SetCursorProperties");
                    
}
                
void ProxyBase<IDirect3DDevice9>::SetCursorPosition(int X, int Y, DWORD Flags)
{
    logMethod("IDirect3DDevice9", "SetCursorPosition");
   
   pimpl_->SetCursorPosition(X, Y, Flags);
   
   ;
                    
}
                
BOOL ProxyBase<IDirect3DDevice9>::ShowCursor(BOOL bShow)
{
    logMethod("IDirect3DDevice9", "ShowCursor");
   
   auto res = pimpl_->ShowCursor(bShow);
   
   return checkReturn(res, "IDirect3DDevice9", "ShowCursor");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
    logMethod("IDirect3DDevice9", "CreateAdditionalSwapChain");
   
   auto res = pimpl_->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
       if (SUCCEEDED(res))
    {
        if (pSwapChain) {*pSwapChain = wrapProxy<IDirect3DSwapChain9>(*pSwapChain).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateAdditionalSwapChain");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
    logMethod("IDirect3DDevice9", "GetSwapChain");
   
   auto res = pimpl_->GetSwapChain(iSwapChain, pSwapChain);
       if (SUCCEEDED(res))
    {
        if (pSwapChain) {*pSwapChain = wrapProxy<IDirect3DSwapChain9>(*pSwapChain).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetSwapChain");
                    
}
                
UINT ProxyBase<IDirect3DDevice9>::GetNumberOfSwapChains()
{
    logMethod("IDirect3DDevice9", "GetNumberOfSwapChains");
   
   auto res = pimpl_->GetNumberOfSwapChains();
   
   return checkReturn(res, "IDirect3DDevice9", "GetNumberOfSwapChains");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    logMethod("IDirect3DDevice9", "Reset");
   
   auto res = pimpl_->Reset(pPresentationParameters);
   
   return checkReturn(res, "IDirect3DDevice9", "Reset");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion)
{
    logMethod("IDirect3DDevice9", "Present");
   
   auto res = pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
   
   return checkReturn(res, "IDirect3DDevice9", "Present");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    logMethod("IDirect3DDevice9", "GetBackBuffer");
   
   auto res = pimpl_->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
       if (SUCCEEDED(res))
    {
        if (ppBackBuffer) {*ppBackBuffer = wrapProxy<IDirect3DSurface9>(*ppBackBuffer).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetBackBuffer");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
    logMethod("IDirect3DDevice9", "GetRasterStatus");
   
   auto res = pimpl_->GetRasterStatus(iSwapChain, pRasterStatus);
   
   return checkReturn(res, "IDirect3DDevice9", "GetRasterStatus");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetDialogBoxMode(BOOL bEnableDialogs)
{
    logMethod("IDirect3DDevice9", "SetDialogBoxMode");
   
   auto res = pimpl_->SetDialogBoxMode(bEnableDialogs);
   
   return checkReturn(res, "IDirect3DDevice9", "SetDialogBoxMode");
                    
}
                
void ProxyBase<IDirect3DDevice9>::SetGammaRamp(UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP* pRamp)
{
    logMethod("IDirect3DDevice9", "SetGammaRamp");
   
   pimpl_->SetGammaRamp(iSwapChain, Flags, pRamp);
   
   ;
                    
}
                
void ProxyBase<IDirect3DDevice9>::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
    logMethod("IDirect3DDevice9", "GetGammaRamp");
   
   pimpl_->GetGammaRamp(iSwapChain, pRamp);
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateTexture");
   
   auto res = pimpl_->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppTexture) {*ppTexture = wrapProxy<IDirect3DTexture9>(*ppTexture).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateTexture");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateVolumeTexture");
   
   auto res = pimpl_->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppVolumeTexture) {*ppVolumeTexture = wrapProxy<IDirect3DVolumeTexture9>(*ppVolumeTexture).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateVolumeTexture");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateCubeTexture");
   
   auto res = pimpl_->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppCubeTexture) {*ppCubeTexture = wrapProxy<IDirect3DCubeTexture9>(*ppCubeTexture).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateCubeTexture");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateVertexBuffer");
   
   auto res = pimpl_->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppVertexBuffer) {*ppVertexBuffer = wrapProxy<IDirect3DVertexBuffer9>(*ppVertexBuffer).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateVertexBuffer");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateIndexBuffer");
   
   auto res = pimpl_->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppIndexBuffer) {*ppIndexBuffer = wrapProxy<IDirect3DIndexBuffer9>(*ppIndexBuffer).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateIndexBuffer");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateRenderTarget");
   
   auto res = pimpl_->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppSurface) {*ppSurface = wrapProxy<IDirect3DSurface9>(*ppSurface).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateRenderTarget");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateDepthStencilSurface");
   
   auto res = pimpl_->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppSurface) {*ppSurface = wrapProxy<IDirect3DSurface9>(*ppSurface).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateDepthStencilSurface");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::UpdateSurface(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, const POINT* pDestPoint)
{
    logMethod("IDirect3DDevice9", "UpdateSurface");
   if (pSourceSurface) {pSourceSurface = unwrapProxy<IDirect3DSurface9>(pSourceSurface);}
        if (pDestinationSurface) {pDestinationSurface = unwrapProxy<IDirect3DSurface9>(pDestinationSurface);}
   auto res = pimpl_->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
   
   return checkReturn(res, "IDirect3DDevice9", "UpdateSurface");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    logMethod("IDirect3DDevice9", "UpdateTexture");
   if (pSourceTexture) {pSourceTexture = unwrapProxy<IDirect3DBaseTexture9>(pSourceTexture);}
        if (pDestinationTexture) {pDestinationTexture = unwrapProxy<IDirect3DBaseTexture9>(pDestinationTexture);}
   auto res = pimpl_->UpdateTexture(pSourceTexture, pDestinationTexture);
   
   return checkReturn(res, "IDirect3DDevice9", "UpdateTexture");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
    logMethod("IDirect3DDevice9", "GetRenderTargetData");
   if (pRenderTarget) {pRenderTarget = unwrapProxy<IDirect3DSurface9>(pRenderTarget);}
        if (pDestSurface) {pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);}
   auto res = pimpl_->GetRenderTargetData(pRenderTarget, pDestSurface);
   
   return checkReturn(res, "IDirect3DDevice9", "GetRenderTargetData");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
    logMethod("IDirect3DDevice9", "GetFrontBufferData");
   if (pDestSurface) {pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);}
   auto res = pimpl_->GetFrontBufferData(iSwapChain, pDestSurface);
   
   return checkReturn(res, "IDirect3DDevice9", "GetFrontBufferData");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::StretchRect(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestSurface, const RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    logMethod("IDirect3DDevice9", "StretchRect");
   if (pSourceSurface) {pSourceSurface = unwrapProxy<IDirect3DSurface9>(pSourceSurface);}
        if (pDestSurface) {pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);}
   auto res = pimpl_->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
   
   return checkReturn(res, "IDirect3DDevice9", "StretchRect");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::ColorFill(IDirect3DSurface9* pSurface, const RECT* pRect, D3DCOLOR color)
{
    logMethod("IDirect3DDevice9", "ColorFill");
   if (pSurface) {pSurface = unwrapProxy<IDirect3DSurface9>(pSurface);}
   auto res = pimpl_->ColorFill(pSurface, pRect, color);
   
   return checkReturn(res, "IDirect3DDevice9", "ColorFill");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    logMethod("IDirect3DDevice9", "CreateOffscreenPlainSurface");
   
   auto res = pimpl_->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
       if (SUCCEEDED(res))
    {
        if (ppSurface) {*ppSurface = wrapProxy<IDirect3DSurface9>(*ppSurface).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateOffscreenPlainSurface");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
    logMethod("IDirect3DDevice9", "SetRenderTarget");
   if (pRenderTarget) {pRenderTarget = unwrapProxy<IDirect3DSurface9>(pRenderTarget);}
   auto res = pimpl_->SetRenderTarget(RenderTargetIndex, pRenderTarget);
   
   return checkReturn(res, "IDirect3DDevice9", "SetRenderTarget");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
    logMethod("IDirect3DDevice9", "GetRenderTarget");
   
   auto res = pimpl_->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
       if (SUCCEEDED(res))
    {
        if (ppRenderTarget) {*ppRenderTarget = wrapProxy<IDirect3DSurface9>(*ppRenderTarget).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetRenderTarget");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
    logMethod("IDirect3DDevice9", "SetDepthStencilSurface");
   if (pNewZStencil) {pNewZStencil = unwrapProxy<IDirect3DSurface9>(pNewZStencil);}
   auto res = pimpl_->SetDepthStencilSurface(pNewZStencil);
   
   return checkReturn(res, "IDirect3DDevice9", "SetDepthStencilSurface");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
    logMethod("IDirect3DDevice9", "GetDepthStencilSurface");
   
   auto res = pimpl_->GetDepthStencilSurface(ppZStencilSurface);
       if (SUCCEEDED(res))
    {
        if (ppZStencilSurface) {*ppZStencilSurface = wrapProxy<IDirect3DSurface9>(*ppZStencilSurface).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetDepthStencilSurface");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::BeginScene()
{
    logMethod("IDirect3DDevice9", "BeginScene");
   
   auto res = pimpl_->BeginScene();
   
   return checkReturn(res, "IDirect3DDevice9", "BeginScene");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::EndScene()
{
    logMethod("IDirect3DDevice9", "EndScene");
   
   auto res = pimpl_->EndScene();
   
   return checkReturn(res, "IDirect3DDevice9", "EndScene");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::Clear(DWORD Count, const D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    logMethod("IDirect3DDevice9", "Clear");
   
   auto res = pimpl_->Clear(Count, pRects, Flags, Color, Z, Stencil);
   
   return checkReturn(res, "IDirect3DDevice9", "Clear");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix)
{
    logMethod("IDirect3DDevice9", "SetTransform");
   
   auto res = pimpl_->SetTransform(State, pMatrix);
   
   return checkReturn(res, "IDirect3DDevice9", "SetTransform");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    logMethod("IDirect3DDevice9", "GetTransform");
   
   auto res = pimpl_->GetTransform(State, pMatrix);
   
   return checkReturn(res, "IDirect3DDevice9", "GetTransform");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::MultiplyTransform(D3DTRANSFORMSTATETYPE unnamed0, const D3DMATRIX* unnamed1)
{
    logMethod("IDirect3DDevice9", "MultiplyTransform");
   
   auto res = pimpl_->MultiplyTransform(unnamed0, unnamed1);
   
   return checkReturn(res, "IDirect3DDevice9", "MultiplyTransform");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetViewport(const D3DVIEWPORT9* pViewport)
{
    logMethod("IDirect3DDevice9", "SetViewport");
   
   auto res = pimpl_->SetViewport(pViewport);
   
   return checkReturn(res, "IDirect3DDevice9", "SetViewport");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetViewport(D3DVIEWPORT9* pViewport)
{
    logMethod("IDirect3DDevice9", "GetViewport");
   
   auto res = pimpl_->GetViewport(pViewport);
   
   return checkReturn(res, "IDirect3DDevice9", "GetViewport");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetMaterial(const D3DMATERIAL9* pMaterial)
{
    logMethod("IDirect3DDevice9", "SetMaterial");
   
   auto res = pimpl_->SetMaterial(pMaterial);
   
   return checkReturn(res, "IDirect3DDevice9", "SetMaterial");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetMaterial(D3DMATERIAL9* pMaterial)
{
    logMethod("IDirect3DDevice9", "GetMaterial");
   
   auto res = pimpl_->GetMaterial(pMaterial);
   
   return checkReturn(res, "IDirect3DDevice9", "GetMaterial");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetLight(DWORD Index, const D3DLIGHT9* unnamed0)
{
    logMethod("IDirect3DDevice9", "SetLight");
   
   auto res = pimpl_->SetLight(Index, unnamed0);
   
   return checkReturn(res, "IDirect3DDevice9", "SetLight");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetLight(DWORD Index, D3DLIGHT9* unnamed0)
{
    logMethod("IDirect3DDevice9", "GetLight");
   
   auto res = pimpl_->GetLight(Index, unnamed0);
   
   return checkReturn(res, "IDirect3DDevice9", "GetLight");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::LightEnable(DWORD Index, BOOL Enable)
{
    logMethod("IDirect3DDevice9", "LightEnable");
   
   auto res = pimpl_->LightEnable(Index, Enable);
   
   return checkReturn(res, "IDirect3DDevice9", "LightEnable");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    logMethod("IDirect3DDevice9", "GetLightEnable");
   
   auto res = pimpl_->GetLightEnable(Index, pEnable);
   
   return checkReturn(res, "IDirect3DDevice9", "GetLightEnable");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetClipPlane(DWORD Index, const float* pPlane)
{
    logMethod("IDirect3DDevice9", "SetClipPlane");
   
   auto res = pimpl_->SetClipPlane(Index, pPlane);
   
   return checkReturn(res, "IDirect3DDevice9", "SetClipPlane");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetClipPlane(DWORD Index, float* pPlane)
{
    logMethod("IDirect3DDevice9", "GetClipPlane");
   
   auto res = pimpl_->GetClipPlane(Index, pPlane);
   
   return checkReturn(res, "IDirect3DDevice9", "GetClipPlane");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    logMethod("IDirect3DDevice9", "SetRenderState");
   
   auto res = pimpl_->SetRenderState(State, Value);
   
   return checkReturn(res, "IDirect3DDevice9", "SetRenderState");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    logMethod("IDirect3DDevice9", "GetRenderState");
   
   auto res = pimpl_->GetRenderState(State, pValue);
   
   return checkReturn(res, "IDirect3DDevice9", "GetRenderState");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
    logMethod("IDirect3DDevice9", "CreateStateBlock");
   
   auto res = pimpl_->CreateStateBlock(Type, ppSB);
       if (SUCCEEDED(res))
    {
        if (ppSB) {*ppSB = wrapProxy<IDirect3DStateBlock9>(*ppSB).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateStateBlock");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::BeginStateBlock()
{
    logMethod("IDirect3DDevice9", "BeginStateBlock");
   
   auto res = pimpl_->BeginStateBlock();
   
   return checkReturn(res, "IDirect3DDevice9", "BeginStateBlock");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
    logMethod("IDirect3DDevice9", "EndStateBlock");
   
   auto res = pimpl_->EndStateBlock(ppSB);
       if (SUCCEEDED(res))
    {
        if (ppSB) {*ppSB = wrapProxy<IDirect3DStateBlock9>(*ppSB).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "EndStateBlock");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetClipStatus(const D3DCLIPSTATUS9* pClipStatus)
{
    logMethod("IDirect3DDevice9", "SetClipStatus");
   
   auto res = pimpl_->SetClipStatus(pClipStatus);
   
   return checkReturn(res, "IDirect3DDevice9", "SetClipStatus");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
    logMethod("IDirect3DDevice9", "GetClipStatus");
   
   auto res = pimpl_->GetClipStatus(pClipStatus);
   
   return checkReturn(res, "IDirect3DDevice9", "GetClipStatus");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    logMethod("IDirect3DDevice9", "GetTexture");
   
   auto res = pimpl_->GetTexture(Stage, ppTexture);
       if (SUCCEEDED(res))
    {
        if (ppTexture) {*ppTexture = wrapProxy<IDirect3DBaseTexture9>(*ppTexture).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetTexture");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    logMethod("IDirect3DDevice9", "SetTexture");
   if (pTexture) {pTexture = unwrapProxy<IDirect3DBaseTexture9>(pTexture);}
   auto res = pimpl_->SetTexture(Stage, pTexture);
   
   return checkReturn(res, "IDirect3DDevice9", "SetTexture");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    logMethod("IDirect3DDevice9", "GetTextureStageState");
   
   auto res = pimpl_->GetTextureStageState(Stage, Type, pValue);
   
   return checkReturn(res, "IDirect3DDevice9", "GetTextureStageState");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    logMethod("IDirect3DDevice9", "SetTextureStageState");
   
   auto res = pimpl_->SetTextureStageState(Stage, Type, Value);
   
   return checkReturn(res, "IDirect3DDevice9", "SetTextureStageState");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
    logMethod("IDirect3DDevice9", "GetSamplerState");
   
   auto res = pimpl_->GetSamplerState(Sampler, Type, pValue);
   
   return checkReturn(res, "IDirect3DDevice9", "GetSamplerState");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    logMethod("IDirect3DDevice9", "SetSamplerState");
   
   auto res = pimpl_->SetSamplerState(Sampler, Type, Value);
   
   return checkReturn(res, "IDirect3DDevice9", "SetSamplerState");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::ValidateDevice(DWORD* pNumPasses)
{
    logMethod("IDirect3DDevice9", "ValidateDevice");
   
   auto res = pimpl_->ValidateDevice(pNumPasses);
   
   return checkReturn(res, "IDirect3DDevice9", "ValidateDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY* pEntries)
{
    logMethod("IDirect3DDevice9", "SetPaletteEntries");
   
   auto res = pimpl_->SetPaletteEntries(PaletteNumber, pEntries);
   
   return checkReturn(res, "IDirect3DDevice9", "SetPaletteEntries");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    logMethod("IDirect3DDevice9", "GetPaletteEntries");
   
   auto res = pimpl_->GetPaletteEntries(PaletteNumber, pEntries);
   
   return checkReturn(res, "IDirect3DDevice9", "GetPaletteEntries");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetCurrentTexturePalette(UINT PaletteNumber)
{
    logMethod("IDirect3DDevice9", "SetCurrentTexturePalette");
   
   auto res = pimpl_->SetCurrentTexturePalette(PaletteNumber);
   
   return checkReturn(res, "IDirect3DDevice9", "SetCurrentTexturePalette");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetCurrentTexturePalette(UINT* PaletteNumber)
{
    logMethod("IDirect3DDevice9", "GetCurrentTexturePalette");
   
   auto res = pimpl_->GetCurrentTexturePalette(PaletteNumber);
   
   return checkReturn(res, "IDirect3DDevice9", "GetCurrentTexturePalette");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetScissorRect(const RECT* pRect)
{
    logMethod("IDirect3DDevice9", "SetScissorRect");
   
   auto res = pimpl_->SetScissorRect(pRect);
   
   return checkReturn(res, "IDirect3DDevice9", "SetScissorRect");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetScissorRect(RECT* pRect)
{
    logMethod("IDirect3DDevice9", "GetScissorRect");
   
   auto res = pimpl_->GetScissorRect(pRect);
   
   return checkReturn(res, "IDirect3DDevice9", "GetScissorRect");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    logMethod("IDirect3DDevice9", "SetSoftwareVertexProcessing");
   
   auto res = pimpl_->SetSoftwareVertexProcessing(bSoftware);
   
   return checkReturn(res, "IDirect3DDevice9", "SetSoftwareVertexProcessing");
                    
}
                
BOOL ProxyBase<IDirect3DDevice9>::GetSoftwareVertexProcessing()
{
    logMethod("IDirect3DDevice9", "GetSoftwareVertexProcessing");
   
   auto res = pimpl_->GetSoftwareVertexProcessing();
   
   return checkReturn(res, "IDirect3DDevice9", "GetSoftwareVertexProcessing");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetNPatchMode(float nSegments)
{
    logMethod("IDirect3DDevice9", "SetNPatchMode");
   
   auto res = pimpl_->SetNPatchMode(nSegments);
   
   return checkReturn(res, "IDirect3DDevice9", "SetNPatchMode");
                    
}
                
float ProxyBase<IDirect3DDevice9>::GetNPatchMode()
{
    logMethod("IDirect3DDevice9", "GetNPatchMode");
   
   auto res = pimpl_->GetNPatchMode();
   
   return checkReturn(res, "IDirect3DDevice9", "GetNPatchMode");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    logMethod("IDirect3DDevice9", "DrawPrimitive");
   
   auto res = pimpl_->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
   
   return checkReturn(res, "IDirect3DDevice9", "DrawPrimitive");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitive(D3DPRIMITIVETYPE unnamed0, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    logMethod("IDirect3DDevice9", "DrawIndexedPrimitive");
   
   auto res = pimpl_->DrawIndexedPrimitive(unnamed0, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
   
   return checkReturn(res, "IDirect3DDevice9", "DrawIndexedPrimitive");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    logMethod("IDirect3DDevice9", "DrawPrimitiveUP");
   
   auto res = pimpl_->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
   
   return checkReturn(res, "IDirect3DDevice9", "DrawPrimitiveUP");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, const void* pIndexData, D3DFORMAT IndexDataFormat, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    logMethod("IDirect3DDevice9", "DrawIndexedPrimitiveUP");
   
   auto res = pimpl_->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
   
   return checkReturn(res, "IDirect3DDevice9", "DrawIndexedPrimitiveUP");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
    logMethod("IDirect3DDevice9", "ProcessVertices");
   if (pDestBuffer) {pDestBuffer = unwrapProxy<IDirect3DVertexBuffer9>(pDestBuffer);}
        if (pVertexDecl) {pVertexDecl = unwrapProxy<IDirect3DVertexDeclaration9>(pVertexDecl);}
   auto res = pimpl_->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
   
   return checkReturn(res, "IDirect3DDevice9", "ProcessVertices");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    logMethod("IDirect3DDevice9", "CreateVertexDeclaration");
   
   auto res = pimpl_->CreateVertexDeclaration(pVertexElements, ppDecl);
       if (SUCCEEDED(res))
    {
        if (ppDecl) {*ppDecl = wrapProxy<IDirect3DVertexDeclaration9>(*ppDecl).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateVertexDeclaration");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
    logMethod("IDirect3DDevice9", "SetVertexDeclaration");
   if (pDecl) {pDecl = unwrapProxy<IDirect3DVertexDeclaration9>(pDecl);}
   auto res = pimpl_->SetVertexDeclaration(pDecl);
   
   return checkReturn(res, "IDirect3DDevice9", "SetVertexDeclaration");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
    logMethod("IDirect3DDevice9", "GetVertexDeclaration");
   
   auto res = pimpl_->GetVertexDeclaration(ppDecl);
       if (SUCCEEDED(res))
    {
        if (ppDecl) {*ppDecl = wrapProxy<IDirect3DVertexDeclaration9>(*ppDecl).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetVertexDeclaration");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetFVF(DWORD FVF)
{
    logMethod("IDirect3DDevice9", "SetFVF");
   
   auto res = pimpl_->SetFVF(FVF);
   
   return checkReturn(res, "IDirect3DDevice9", "SetFVF");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetFVF(DWORD* pFVF)
{
    logMethod("IDirect3DDevice9", "GetFVF");
   
   auto res = pimpl_->GetFVF(pFVF);
   
   return checkReturn(res, "IDirect3DDevice9", "GetFVF");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexShader(const DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    logMethod("IDirect3DDevice9", "CreateVertexShader");
   
   auto res = pimpl_->CreateVertexShader(pFunction, ppShader);
       if (SUCCEEDED(res))
    {
        if (ppShader) {*ppShader = wrapProxy<IDirect3DVertexShader9>(*ppShader).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateVertexShader");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShader(IDirect3DVertexShader9* pShader)
{
    logMethod("IDirect3DDevice9", "SetVertexShader");
   if (pShader) {pShader = unwrapProxy<IDirect3DVertexShader9>(pShader);}
   auto res = pimpl_->SetVertexShader(pShader);
   
   return checkReturn(res, "IDirect3DDevice9", "SetVertexShader");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
    logMethod("IDirect3DDevice9", "GetVertexShader");
   
   auto res = pimpl_->GetVertexShader(ppShader);
       if (SUCCEEDED(res))
    {
        if (ppShader) {*ppShader = wrapProxy<IDirect3DVertexShader9>(*ppShader).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetVertexShader");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
    logMethod("IDirect3DDevice9", "SetVertexShaderConstantF");
   
   auto res = pimpl_->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return checkReturn(res, "IDirect3DDevice9", "SetVertexShaderConstantF");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    logMethod("IDirect3DDevice9", "GetVertexShaderConstantF");
   
   auto res = pimpl_->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return checkReturn(res, "IDirect3DDevice9", "GetVertexShaderConstantF");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
    logMethod("IDirect3DDevice9", "SetVertexShaderConstantI");
   
   auto res = pimpl_->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return checkReturn(res, "IDirect3DDevice9", "SetVertexShaderConstantI");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    logMethod("IDirect3DDevice9", "GetVertexShaderConstantI");
   
   auto res = pimpl_->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return checkReturn(res, "IDirect3DDevice9", "GetVertexShaderConstantI");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
    logMethod("IDirect3DDevice9", "SetVertexShaderConstantB");
   
   auto res = pimpl_->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return checkReturn(res, "IDirect3DDevice9", "SetVertexShaderConstantB");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    logMethod("IDirect3DDevice9", "GetVertexShaderConstantB");
   
   auto res = pimpl_->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return checkReturn(res, "IDirect3DDevice9", "GetVertexShaderConstantB");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
    logMethod("IDirect3DDevice9", "SetStreamSource");
   if (pStreamData) {pStreamData = unwrapProxy<IDirect3DVertexBuffer9>(pStreamData);}
   auto res = pimpl_->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
   
   return checkReturn(res, "IDirect3DDevice9", "SetStreamSource");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
    logMethod("IDirect3DDevice9", "GetStreamSource");
   
   auto res = pimpl_->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
       if (SUCCEEDED(res))
    {
        if (ppStreamData) {*ppStreamData = wrapProxy<IDirect3DVertexBuffer9>(*ppStreamData).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetStreamSource");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetStreamSourceFreq(UINT StreamNumber, UINT Setting)
{
    logMethod("IDirect3DDevice9", "SetStreamSourceFreq");
   
   auto res = pimpl_->SetStreamSourceFreq(StreamNumber, Setting);
   
   return checkReturn(res, "IDirect3DDevice9", "SetStreamSourceFreq");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting)
{
    logMethod("IDirect3DDevice9", "GetStreamSourceFreq");
   
   auto res = pimpl_->GetStreamSourceFreq(StreamNumber, pSetting);
   
   return checkReturn(res, "IDirect3DDevice9", "GetStreamSourceFreq");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
    logMethod("IDirect3DDevice9", "SetIndices");
   if (pIndexData) {pIndexData = unwrapProxy<IDirect3DIndexBuffer9>(pIndexData);}
   auto res = pimpl_->SetIndices(pIndexData);
   
   return checkReturn(res, "IDirect3DDevice9", "SetIndices");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
    logMethod("IDirect3DDevice9", "GetIndices");
   
   auto res = pimpl_->GetIndices(ppIndexData);
       if (SUCCEEDED(res))
    {
        if (ppIndexData) {*ppIndexData = wrapProxy<IDirect3DIndexBuffer9>(*ppIndexData).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetIndices");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreatePixelShader(const DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    logMethod("IDirect3DDevice9", "CreatePixelShader");
   
   auto res = pimpl_->CreatePixelShader(pFunction, ppShader);
       if (SUCCEEDED(res))
    {
        if (ppShader) {*ppShader = wrapProxy<IDirect3DPixelShader9>(*ppShader).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreatePixelShader");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShader(IDirect3DPixelShader9* pShader)
{
    logMethod("IDirect3DDevice9", "SetPixelShader");
   if (pShader) {pShader = unwrapProxy<IDirect3DPixelShader9>(pShader);}
   auto res = pimpl_->SetPixelShader(pShader);
   
   return checkReturn(res, "IDirect3DDevice9", "SetPixelShader");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
    logMethod("IDirect3DDevice9", "GetPixelShader");
   
   auto res = pimpl_->GetPixelShader(ppShader);
       if (SUCCEEDED(res))
    {
        if (ppShader) {*ppShader = wrapProxy<IDirect3DPixelShader9>(*ppShader).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "GetPixelShader");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
    logMethod("IDirect3DDevice9", "SetPixelShaderConstantF");
   
   auto res = pimpl_->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return checkReturn(res, "IDirect3DDevice9", "SetPixelShaderConstantF");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    logMethod("IDirect3DDevice9", "GetPixelShaderConstantF");
   
   auto res = pimpl_->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return checkReturn(res, "IDirect3DDevice9", "GetPixelShaderConstantF");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
    logMethod("IDirect3DDevice9", "SetPixelShaderConstantI");
   
   auto res = pimpl_->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return checkReturn(res, "IDirect3DDevice9", "SetPixelShaderConstantI");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    logMethod("IDirect3DDevice9", "GetPixelShaderConstantI");
   
   auto res = pimpl_->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return checkReturn(res, "IDirect3DDevice9", "GetPixelShaderConstantI");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
    logMethod("IDirect3DDevice9", "SetPixelShaderConstantB");
   
   auto res = pimpl_->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return checkReturn(res, "IDirect3DDevice9", "SetPixelShaderConstantB");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    logMethod("IDirect3DDevice9", "GetPixelShaderConstantB");
   
   auto res = pimpl_->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return checkReturn(res, "IDirect3DDevice9", "GetPixelShaderConstantB");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawRectPatch(UINT Handle, const float* pNumSegs, const D3DRECTPATCH_INFO* pRectPatchInfo)
{
    logMethod("IDirect3DDevice9", "DrawRectPatch");
   
   auto res = pimpl_->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
   
   return checkReturn(res, "IDirect3DDevice9", "DrawRectPatch");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawTriPatch(UINT Handle, const float* pNumSegs, const D3DTRIPATCH_INFO* pTriPatchInfo)
{
    logMethod("IDirect3DDevice9", "DrawTriPatch");
   
   auto res = pimpl_->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
   
   return checkReturn(res, "IDirect3DDevice9", "DrawTriPatch");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DeletePatch(UINT Handle)
{
    logMethod("IDirect3DDevice9", "DeletePatch");
   
   auto res = pimpl_->DeletePatch(Handle);
   
   return checkReturn(res, "IDirect3DDevice9", "DeletePatch");
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    logMethod("IDirect3DDevice9", "CreateQuery");
   
   auto res = pimpl_->CreateQuery(Type, ppQuery);
       if (SUCCEEDED(res))
    {
        if (ppQuery) {*ppQuery = wrapProxy<IDirect3DQuery9>(*ppQuery).get();}
    }
                        
   return checkReturn(res, "IDirect3DDevice9", "CreateQuery");
                    
}
                
ProxyBase<IDirect3DStateBlock9>::ProxyBase(IDirect3DStateBlock9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DStateBlock9 *ProxyBase<IDirect3DStateBlock9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DStateBlock9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DStateBlock9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DStateBlock9>::AddRef()
{
    logMethod("IDirect3DStateBlock9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DStateBlock9>::Release()
{
    logMethod("IDirect3DStateBlock9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DStateBlock9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DStateBlock9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DStateBlock9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DStateBlock9>::Capture()
{
    logMethod("IDirect3DStateBlock9", "Capture");
   
   auto res = pimpl_->Capture();
   
   return checkReturn(res, "IDirect3DStateBlock9", "Capture");
                    
}
                
HRESULT ProxyBase<IDirect3DStateBlock9>::Apply()
{
    logMethod("IDirect3DStateBlock9", "Apply");
   
   auto res = pimpl_->Apply();
   
   return checkReturn(res, "IDirect3DStateBlock9", "Apply");
                    
}
                
ProxyBase<IDirect3DSwapChain9>::ProxyBase(IDirect3DSwapChain9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DSwapChain9 *ProxyBase<IDirect3DSwapChain9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DSwapChain9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DSwapChain9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DSwapChain9>::AddRef()
{
    logMethod("IDirect3DSwapChain9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DSwapChain9>::Release()
{
    logMethod("IDirect3DSwapChain9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion, DWORD dwFlags)
{
    logMethod("IDirect3DSwapChain9", "Present");
   
   auto res = pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion, dwFlags);
   
   return checkReturn(res, "IDirect3DSwapChain9", "Present");
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetFrontBufferData(IDirect3DSurface9* pDestSurface)
{
    logMethod("IDirect3DSwapChain9", "GetFrontBufferData");
   if (pDestSurface) {pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);}
   auto res = pimpl_->GetFrontBufferData(pDestSurface);
   
   return checkReturn(res, "IDirect3DSwapChain9", "GetFrontBufferData");
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    logMethod("IDirect3DSwapChain9", "GetBackBuffer");
   
   auto res = pimpl_->GetBackBuffer(iBackBuffer, Type, ppBackBuffer);
       if (SUCCEEDED(res))
    {
        if (ppBackBuffer) {*ppBackBuffer = wrapProxy<IDirect3DSurface9>(*ppBackBuffer).get();}
    }
                        
   return checkReturn(res, "IDirect3DSwapChain9", "GetBackBuffer");
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
    logMethod("IDirect3DSwapChain9", "GetRasterStatus");
   
   auto res = pimpl_->GetRasterStatus(pRasterStatus);
   
   return checkReturn(res, "IDirect3DSwapChain9", "GetRasterStatus");
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
    logMethod("IDirect3DSwapChain9", "GetDisplayMode");
   
   auto res = pimpl_->GetDisplayMode(pMode);
   
   return checkReturn(res, "IDirect3DSwapChain9", "GetDisplayMode");
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DSwapChain9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DSwapChain9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetPresentParameters(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    logMethod("IDirect3DSwapChain9", "GetPresentParameters");
   
   auto res = pimpl_->GetPresentParameters(pPresentationParameters);
   
   return checkReturn(res, "IDirect3DSwapChain9", "GetPresentParameters");
                    
}
                
ProxyBase<IDirect3DVertexDeclaration9>::ProxyBase(IDirect3DVertexDeclaration9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DVertexDeclaration9 *ProxyBase<IDirect3DVertexDeclaration9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVertexDeclaration9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DVertexDeclaration9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DVertexDeclaration9>::AddRef()
{
    logMethod("IDirect3DVertexDeclaration9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DVertexDeclaration9>::Release()
{
    logMethod("IDirect3DVertexDeclaration9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexDeclaration9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DVertexDeclaration9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DVertexDeclaration9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexDeclaration9>::GetDeclaration(D3DVERTEXELEMENT9* pElement, UINT* pNumElements)
{
    logMethod("IDirect3DVertexDeclaration9", "GetDeclaration");
   
   auto res = pimpl_->GetDeclaration(pElement, pNumElements);
   
   return checkReturn(res, "IDirect3DVertexDeclaration9", "GetDeclaration");
                    
}
                
ProxyBase<IDirect3DVertexShader9>::ProxyBase(IDirect3DVertexShader9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DVertexShader9 *ProxyBase<IDirect3DVertexShader9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVertexShader9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DVertexShader9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DVertexShader9>::AddRef()
{
    logMethod("IDirect3DVertexShader9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DVertexShader9>::Release()
{
    logMethod("IDirect3DVertexShader9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexShader9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DVertexShader9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DVertexShader9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexShader9>::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
    logMethod("IDirect3DVertexShader9", "GetFunction");
   
   auto res = pimpl_->GetFunction(unnamed0, pSizeOfData);
   
   return checkReturn(res, "IDirect3DVertexShader9", "GetFunction");
                    
}
                
ProxyBase<IDirect3DPixelShader9>::ProxyBase(IDirect3DPixelShader9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DPixelShader9 *ProxyBase<IDirect3DPixelShader9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DPixelShader9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DPixelShader9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DPixelShader9>::AddRef()
{
    logMethod("IDirect3DPixelShader9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DPixelShader9>::Release()
{
    logMethod("IDirect3DPixelShader9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DPixelShader9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DPixelShader9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DPixelShader9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DPixelShader9>::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
    logMethod("IDirect3DPixelShader9", "GetFunction");
   
   auto res = pimpl_->GetFunction(unnamed0, pSizeOfData);
   
   return checkReturn(res, "IDirect3DPixelShader9", "GetFunction");
                    
}
                
ProxyBase<IDirect3DTexture9>::ProxyBase(IDirect3DTexture9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DTexture9 *ProxyBase<IDirect3DTexture9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DTexture9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DTexture9>::AddRef()
{
    logMethod("IDirect3DTexture9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DTexture9>::Release()
{
    logMethod("IDirect3DTexture9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DTexture9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DTexture9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DTexture9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DTexture9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DTexture9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DTexture9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DTexture9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DTexture9", "FreePrivateData");
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::SetPriority(DWORD PriorityNew)
{
    logMethod("IDirect3DTexture9", "SetPriority");
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return checkReturn(res, "IDirect3DTexture9", "SetPriority");
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::GetPriority()
{
    logMethod("IDirect3DTexture9", "GetPriority");
   
   auto res = pimpl_->GetPriority();
   
   return checkReturn(res, "IDirect3DTexture9", "GetPriority");
                    
}
                
void ProxyBase<IDirect3DTexture9>::PreLoad()
{
    logMethod("IDirect3DTexture9", "PreLoad");
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DTexture9>::GetType()
{
    logMethod("IDirect3DTexture9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DTexture9", "GetType");
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::SetLOD(DWORD LODNew)
{
    logMethod("IDirect3DTexture9", "SetLOD");
   
   auto res = pimpl_->SetLOD(LODNew);
   
   return checkReturn(res, "IDirect3DTexture9", "SetLOD");
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::GetLOD()
{
    logMethod("IDirect3DTexture9", "GetLOD");
   
   auto res = pimpl_->GetLOD();
   
   return checkReturn(res, "IDirect3DTexture9", "GetLOD");
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::GetLevelCount()
{
    logMethod("IDirect3DTexture9", "GetLevelCount");
   
   auto res = pimpl_->GetLevelCount();
   
   return checkReturn(res, "IDirect3DTexture9", "GetLevelCount");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    logMethod("IDirect3DTexture9", "SetAutoGenFilterType");
   
   auto res = pimpl_->SetAutoGenFilterType(FilterType);
   
   return checkReturn(res, "IDirect3DTexture9", "SetAutoGenFilterType");
                    
}
                
D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DTexture9>::GetAutoGenFilterType()
{
    logMethod("IDirect3DTexture9", "GetAutoGenFilterType");
   
   auto res = pimpl_->GetAutoGenFilterType();
   
   return checkReturn(res, "IDirect3DTexture9", "GetAutoGenFilterType");
                    
}
                
void ProxyBase<IDirect3DTexture9>::GenerateMipSubLevels()
{
    logMethod("IDirect3DTexture9", "GenerateMipSubLevels");
   
   pimpl_->GenerateMipSubLevels();
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
    logMethod("IDirect3DTexture9", "GetLevelDesc");
   
   auto res = pimpl_->GetLevelDesc(Level, pDesc);
   
   return checkReturn(res, "IDirect3DTexture9", "GetLevelDesc");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel)
{
    logMethod("IDirect3DTexture9", "GetSurfaceLevel");
   
   auto res = pimpl_->GetSurfaceLevel(Level, ppSurfaceLevel);
       if (SUCCEEDED(res))
    {
        if (ppSurfaceLevel) {*ppSurfaceLevel = wrapProxy<IDirect3DSurface9>(*ppSurfaceLevel).get();}
    }
                        
   return checkReturn(res, "IDirect3DTexture9", "GetSurfaceLevel");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    logMethod("IDirect3DTexture9", "LockRect");
   
   auto res = pimpl_->LockRect(Level, pLockedRect, pRect, Flags);
   
   return checkReturn(res, "IDirect3DTexture9", "LockRect");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::UnlockRect(UINT Level)
{
    logMethod("IDirect3DTexture9", "UnlockRect");
   
   auto res = pimpl_->UnlockRect(Level);
   
   return checkReturn(res, "IDirect3DTexture9", "UnlockRect");
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::AddDirtyRect(const RECT* pDirtyRect)
{
    logMethod("IDirect3DTexture9", "AddDirtyRect");
   
   auto res = pimpl_->AddDirtyRect(pDirtyRect);
   
   return checkReturn(res, "IDirect3DTexture9", "AddDirtyRect");
                    
}
                
ProxyBase<IDirect3DVolumeTexture9>::ProxyBase(IDirect3DVolumeTexture9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DVolumeTexture9 *ProxyBase<IDirect3DVolumeTexture9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVolumeTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DVolumeTexture9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DVolumeTexture9>::AddRef()
{
    logMethod("IDirect3DVolumeTexture9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DVolumeTexture9>::Release()
{
    logMethod("IDirect3DVolumeTexture9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DVolumeTexture9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DVolumeTexture9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DVolumeTexture9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DVolumeTexture9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "FreePrivateData");
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::SetPriority(DWORD PriorityNew)
{
    logMethod("IDirect3DVolumeTexture9", "SetPriority");
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "SetPriority");
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::GetPriority()
{
    logMethod("IDirect3DVolumeTexture9", "GetPriority");
   
   auto res = pimpl_->GetPriority();
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetPriority");
                    
}
                
void ProxyBase<IDirect3DVolumeTexture9>::PreLoad()
{
    logMethod("IDirect3DVolumeTexture9", "PreLoad");
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DVolumeTexture9>::GetType()
{
    logMethod("IDirect3DVolumeTexture9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetType");
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::SetLOD(DWORD LODNew)
{
    logMethod("IDirect3DVolumeTexture9", "SetLOD");
   
   auto res = pimpl_->SetLOD(LODNew);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "SetLOD");
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::GetLOD()
{
    logMethod("IDirect3DVolumeTexture9", "GetLOD");
   
   auto res = pimpl_->GetLOD();
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetLOD");
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::GetLevelCount()
{
    logMethod("IDirect3DVolumeTexture9", "GetLevelCount");
   
   auto res = pimpl_->GetLevelCount();
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetLevelCount");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    logMethod("IDirect3DVolumeTexture9", "SetAutoGenFilterType");
   
   auto res = pimpl_->SetAutoGenFilterType(FilterType);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "SetAutoGenFilterType");
                    
}
                
D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DVolumeTexture9>::GetAutoGenFilterType()
{
    logMethod("IDirect3DVolumeTexture9", "GetAutoGenFilterType");
   
   auto res = pimpl_->GetAutoGenFilterType();
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetAutoGenFilterType");
                    
}
                
void ProxyBase<IDirect3DVolumeTexture9>::GenerateMipSubLevels()
{
    logMethod("IDirect3DVolumeTexture9", "GenerateMipSubLevels");
   
   pimpl_->GenerateMipSubLevels();
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetLevelDesc(UINT Level, D3DVOLUME_DESC* pDesc)
{
    logMethod("IDirect3DVolumeTexture9", "GetLevelDesc");
   
   auto res = pimpl_->GetLevelDesc(Level, pDesc);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetLevelDesc");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetVolumeLevel(UINT Level, IDirect3DVolume9** ppVolumeLevel)
{
    logMethod("IDirect3DVolumeTexture9", "GetVolumeLevel");
   
   auto res = pimpl_->GetVolumeLevel(Level, ppVolumeLevel);
       if (SUCCEEDED(res))
    {
        if (ppVolumeLevel) {*ppVolumeLevel = wrapProxy<IDirect3DVolume9>(*ppVolumeLevel).get();}
    }
                        
   return checkReturn(res, "IDirect3DVolumeTexture9", "GetVolumeLevel");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::LockBox(UINT Level, D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
    logMethod("IDirect3DVolumeTexture9", "LockBox");
   
   auto res = pimpl_->LockBox(Level, pLockedVolume, pBox, Flags);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "LockBox");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::UnlockBox(UINT Level)
{
    logMethod("IDirect3DVolumeTexture9", "UnlockBox");
   
   auto res = pimpl_->UnlockBox(Level);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "UnlockBox");
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::AddDirtyBox(const D3DBOX* pDirtyBox)
{
    logMethod("IDirect3DVolumeTexture9", "AddDirtyBox");
   
   auto res = pimpl_->AddDirtyBox(pDirtyBox);
   
   return checkReturn(res, "IDirect3DVolumeTexture9", "AddDirtyBox");
                    
}
                
ProxyBase<IDirect3DCubeTexture9>::ProxyBase(IDirect3DCubeTexture9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DCubeTexture9 *ProxyBase<IDirect3DCubeTexture9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DCubeTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DCubeTexture9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DCubeTexture9>::AddRef()
{
    logMethod("IDirect3DCubeTexture9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DCubeTexture9>::Release()
{
    logMethod("IDirect3DCubeTexture9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DCubeTexture9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DCubeTexture9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DCubeTexture9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DCubeTexture9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DCubeTexture9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "FreePrivateData");
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::SetPriority(DWORD PriorityNew)
{
    logMethod("IDirect3DCubeTexture9", "SetPriority");
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "SetPriority");
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::GetPriority()
{
    logMethod("IDirect3DCubeTexture9", "GetPriority");
   
   auto res = pimpl_->GetPriority();
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetPriority");
                    
}
                
void ProxyBase<IDirect3DCubeTexture9>::PreLoad()
{
    logMethod("IDirect3DCubeTexture9", "PreLoad");
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DCubeTexture9>::GetType()
{
    logMethod("IDirect3DCubeTexture9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetType");
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::SetLOD(DWORD LODNew)
{
    logMethod("IDirect3DCubeTexture9", "SetLOD");
   
   auto res = pimpl_->SetLOD(LODNew);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "SetLOD");
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::GetLOD()
{
    logMethod("IDirect3DCubeTexture9", "GetLOD");
   
   auto res = pimpl_->GetLOD();
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetLOD");
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::GetLevelCount()
{
    logMethod("IDirect3DCubeTexture9", "GetLevelCount");
   
   auto res = pimpl_->GetLevelCount();
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetLevelCount");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    logMethod("IDirect3DCubeTexture9", "SetAutoGenFilterType");
   
   auto res = pimpl_->SetAutoGenFilterType(FilterType);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "SetAutoGenFilterType");
                    
}
                
D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DCubeTexture9>::GetAutoGenFilterType()
{
    logMethod("IDirect3DCubeTexture9", "GetAutoGenFilterType");
   
   auto res = pimpl_->GetAutoGenFilterType();
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetAutoGenFilterType");
                    
}
                
void ProxyBase<IDirect3DCubeTexture9>::GenerateMipSubLevels()
{
    logMethod("IDirect3DCubeTexture9", "GenerateMipSubLevels");
   
   pimpl_->GenerateMipSubLevels();
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
    logMethod("IDirect3DCubeTexture9", "GetLevelDesc");
   
   auto res = pimpl_->GetLevelDesc(Level, pDesc);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "GetLevelDesc");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9** ppCubeMapSurface)
{
    logMethod("IDirect3DCubeTexture9", "GetCubeMapSurface");
   
   auto res = pimpl_->GetCubeMapSurface(FaceType, Level, ppCubeMapSurface);
       if (SUCCEEDED(res))
    {
        if (ppCubeMapSurface) {*ppCubeMapSurface = wrapProxy<IDirect3DSurface9>(*ppCubeMapSurface).get();}
    }
                        
   return checkReturn(res, "IDirect3DCubeTexture9", "GetCubeMapSurface");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    logMethod("IDirect3DCubeTexture9", "LockRect");
   
   auto res = pimpl_->LockRect(FaceType, Level, pLockedRect, pRect, Flags);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "LockRect");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level)
{
    logMethod("IDirect3DCubeTexture9", "UnlockRect");
   
   auto res = pimpl_->UnlockRect(FaceType, Level);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "UnlockRect");
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT* pDirtyRect)
{
    logMethod("IDirect3DCubeTexture9", "AddDirtyRect");
   
   auto res = pimpl_->AddDirtyRect(FaceType, pDirtyRect);
   
   return checkReturn(res, "IDirect3DCubeTexture9", "AddDirtyRect");
                    
}
                
ProxyBase<IDirect3DVertexBuffer9>::ProxyBase(IDirect3DVertexBuffer9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DVertexBuffer9 *ProxyBase<IDirect3DVertexBuffer9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVertexBuffer9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DVertexBuffer9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DVertexBuffer9>::AddRef()
{
    logMethod("IDirect3DVertexBuffer9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DVertexBuffer9>::Release()
{
    logMethod("IDirect3DVertexBuffer9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DVertexBuffer9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DVertexBuffer9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DVertexBuffer9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DVertexBuffer9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DVertexBuffer9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "FreePrivateData");
                    
}
                
DWORD ProxyBase<IDirect3DVertexBuffer9>::SetPriority(DWORD PriorityNew)
{
    logMethod("IDirect3DVertexBuffer9", "SetPriority");
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "SetPriority");
                    
}
                
DWORD ProxyBase<IDirect3DVertexBuffer9>::GetPriority()
{
    logMethod("IDirect3DVertexBuffer9", "GetPriority");
   
   auto res = pimpl_->GetPriority();
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "GetPriority");
                    
}
                
void ProxyBase<IDirect3DVertexBuffer9>::PreLoad()
{
    logMethod("IDirect3DVertexBuffer9", "PreLoad");
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DVertexBuffer9>::GetType()
{
    logMethod("IDirect3DVertexBuffer9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "GetType");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    logMethod("IDirect3DVertexBuffer9", "Lock");
   
   auto res = pimpl_->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "Lock");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::Unlock()
{
    logMethod("IDirect3DVertexBuffer9", "Unlock");
   
   auto res = pimpl_->Unlock();
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "Unlock");
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetDesc(D3DVERTEXBUFFER_DESC* pDesc)
{
    logMethod("IDirect3DVertexBuffer9", "GetDesc");
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return checkReturn(res, "IDirect3DVertexBuffer9", "GetDesc");
                    
}
                
ProxyBase<IDirect3DIndexBuffer9>::ProxyBase(IDirect3DIndexBuffer9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DIndexBuffer9 *ProxyBase<IDirect3DIndexBuffer9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DIndexBuffer9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DIndexBuffer9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DIndexBuffer9>::AddRef()
{
    logMethod("IDirect3DIndexBuffer9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DIndexBuffer9>::Release()
{
    logMethod("IDirect3DIndexBuffer9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DIndexBuffer9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DIndexBuffer9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DIndexBuffer9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DIndexBuffer9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DIndexBuffer9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "FreePrivateData");
                    
}
                
DWORD ProxyBase<IDirect3DIndexBuffer9>::SetPriority(DWORD PriorityNew)
{
    logMethod("IDirect3DIndexBuffer9", "SetPriority");
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "SetPriority");
                    
}
                
DWORD ProxyBase<IDirect3DIndexBuffer9>::GetPriority()
{
    logMethod("IDirect3DIndexBuffer9", "GetPriority");
   
   auto res = pimpl_->GetPriority();
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "GetPriority");
                    
}
                
void ProxyBase<IDirect3DIndexBuffer9>::PreLoad()
{
    logMethod("IDirect3DIndexBuffer9", "PreLoad");
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DIndexBuffer9>::GetType()
{
    logMethod("IDirect3DIndexBuffer9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "GetType");
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    logMethod("IDirect3DIndexBuffer9", "Lock");
   
   auto res = pimpl_->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "Lock");
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::Unlock()
{
    logMethod("IDirect3DIndexBuffer9", "Unlock");
   
   auto res = pimpl_->Unlock();
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "Unlock");
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetDesc(D3DINDEXBUFFER_DESC* pDesc)
{
    logMethod("IDirect3DIndexBuffer9", "GetDesc");
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return checkReturn(res, "IDirect3DIndexBuffer9", "GetDesc");
                    
}
                
ProxyBase<IDirect3DSurface9>::ProxyBase(IDirect3DSurface9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DSurface9 *ProxyBase<IDirect3DSurface9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DSurface9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DSurface9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DSurface9>::AddRef()
{
    logMethod("IDirect3DSurface9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DSurface9>::Release()
{
    logMethod("IDirect3DSurface9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DSurface9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DSurface9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DSurface9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DSurface9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DSurface9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DSurface9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DSurface9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DSurface9", "FreePrivateData");
                    
}
                
DWORD ProxyBase<IDirect3DSurface9>::SetPriority(DWORD PriorityNew)
{
    logMethod("IDirect3DSurface9", "SetPriority");
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return checkReturn(res, "IDirect3DSurface9", "SetPriority");
                    
}
                
DWORD ProxyBase<IDirect3DSurface9>::GetPriority()
{
    logMethod("IDirect3DSurface9", "GetPriority");
   
   auto res = pimpl_->GetPriority();
   
   return checkReturn(res, "IDirect3DSurface9", "GetPriority");
                    
}
                
void ProxyBase<IDirect3DSurface9>::PreLoad()
{
    logMethod("IDirect3DSurface9", "PreLoad");
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DSurface9>::GetType()
{
    logMethod("IDirect3DSurface9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DSurface9", "GetType");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetContainer(REFIID riid, void** ppContainer)
{
    logMethod("IDirect3DSurface9", "GetContainer");
   
   auto res = pimpl_->GetContainer(riid, ppContainer);
   
   return checkReturn(res, "IDirect3DSurface9", "GetContainer");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetDesc(D3DSURFACE_DESC* pDesc)
{
    logMethod("IDirect3DSurface9", "GetDesc");
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return checkReturn(res, "IDirect3DSurface9", "GetDesc");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    logMethod("IDirect3DSurface9", "LockRect");
   
   auto res = pimpl_->LockRect(pLockedRect, pRect, Flags);
   
   return checkReturn(res, "IDirect3DSurface9", "LockRect");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::UnlockRect()
{
    logMethod("IDirect3DSurface9", "UnlockRect");
   
   auto res = pimpl_->UnlockRect();
   
   return checkReturn(res, "IDirect3DSurface9", "UnlockRect");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetDC(HDC* phdc)
{
    logMethod("IDirect3DSurface9", "GetDC");
   
   auto res = pimpl_->GetDC(phdc);
   
   return checkReturn(res, "IDirect3DSurface9", "GetDC");
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::ReleaseDC(HDC hdc)
{
    logMethod("IDirect3DSurface9", "ReleaseDC");
   
   auto res = pimpl_->ReleaseDC(hdc);
   
   return checkReturn(res, "IDirect3DSurface9", "ReleaseDC");
                    
}
                
ProxyBase<IDirect3DVolume9>::ProxyBase(IDirect3DVolume9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DVolume9 *ProxyBase<IDirect3DVolume9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVolume9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DVolume9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DVolume9>::AddRef()
{
    logMethod("IDirect3DVolume9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DVolume9>::Release()
{
    logMethod("IDirect3DVolume9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DVolume9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DVolume9", "GetDevice");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
    logMethod("IDirect3DVolume9", "SetPrivateData");
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return checkReturn(res, "IDirect3DVolume9", "SetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    logMethod("IDirect3DVolume9", "GetPrivateData");
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return checkReturn(res, "IDirect3DVolume9", "GetPrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::FreePrivateData(REFGUID refguid)
{
    logMethod("IDirect3DVolume9", "FreePrivateData");
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return checkReturn(res, "IDirect3DVolume9", "FreePrivateData");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetContainer(REFIID riid, void** ppContainer)
{
    logMethod("IDirect3DVolume9", "GetContainer");
   
   auto res = pimpl_->GetContainer(riid, ppContainer);
   
   return checkReturn(res, "IDirect3DVolume9", "GetContainer");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetDesc(D3DVOLUME_DESC* pDesc)
{
    logMethod("IDirect3DVolume9", "GetDesc");
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return checkReturn(res, "IDirect3DVolume9", "GetDesc");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::LockBox(D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
    logMethod("IDirect3DVolume9", "LockBox");
   
   auto res = pimpl_->LockBox(pLockedVolume, pBox, Flags);
   
   return checkReturn(res, "IDirect3DVolume9", "LockBox");
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::UnlockBox()
{
    logMethod("IDirect3DVolume9", "UnlockBox");
   
   auto res = pimpl_->UnlockBox();
   
   return checkReturn(res, "IDirect3DVolume9", "UnlockBox");
                    
}
                
ProxyBase<IDirect3DQuery9>::ProxyBase(IDirect3DQuery9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(0)
    , goingToDie_(false)
    , refCount_(0)
{
}
            
IDirect3DQuery9 *ProxyBase<IDirect3DQuery9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DQuery9>::QueryInterface(REFIID riid, void** ppvObj)
{
    logMethod("IDirect3DQuery9", "QueryInterface");
    auto res = pimpl_->QueryInterface(riid, ppvObj);
    LogQI(riid);
    return res;
                    
}
                
ULONG ProxyBase<IDirect3DQuery9>::AddRef()
{
    logMethod("IDirect3DQuery9", "AddRef");
    refCount_ = pimpl_->AddRef();
    ++extRefCount_;
    assert(refCount_ >= extRefCount_);
    return refCount_;
                    
}
                
ULONG ProxyBase<IDirect3DQuery9>::Release()
{
    logMethod("IDirect3DQuery9", "Release");
    refCount_ = pimpl_->Release();
    --extRefCount_;
    assert(refCount_ >= extRefCount_);
    if (!goingToDie_)
    {
        assert(extRefCount_ > 0);
        if (extRefCount_ == 1)
        {
            goingToDie_ = true;
            detachProxy(pimpl_);
            assert(extRefCount_ == 0);
            delete this;
        }
    }
    return refCount_;
                    
}
                
HRESULT ProxyBase<IDirect3DQuery9>::GetDevice(IDirect3DDevice9** ppDevice)
{
    logMethod("IDirect3DQuery9", "GetDevice");
   
   auto res = pimpl_->GetDevice(ppDevice);
       if (SUCCEEDED(res))
    {
        if (ppDevice) {*ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();}
    }
                        
   return checkReturn(res, "IDirect3DQuery9", "GetDevice");
                    
}
                
D3DQUERYTYPE ProxyBase<IDirect3DQuery9>::GetType()
{
    logMethod("IDirect3DQuery9", "GetType");
   
   auto res = pimpl_->GetType();
   
   return checkReturn(res, "IDirect3DQuery9", "GetType");
                    
}
                
DWORD ProxyBase<IDirect3DQuery9>::GetDataSize()
{
    logMethod("IDirect3DQuery9", "GetDataSize");
   
   auto res = pimpl_->GetDataSize();
   
   return checkReturn(res, "IDirect3DQuery9", "GetDataSize");
                    
}
                
HRESULT ProxyBase<IDirect3DQuery9>::Issue(DWORD dwIssueFlags)
{
    logMethod("IDirect3DQuery9", "Issue");
   
   auto res = pimpl_->Issue(dwIssueFlags);
   
   return checkReturn(res, "IDirect3DQuery9", "Issue");
                    
}
                
HRESULT ProxyBase<IDirect3DQuery9>::GetData(void* pData, DWORD dwSize, DWORD dwGetDataFlags)
{
    logMethod("IDirect3DQuery9", "GetData");
   
   auto res = pimpl_->GetData(pData, dwSize, dwGetDataFlags);
   
   return checkReturn(res, "IDirect3DQuery9", "GetData");
                    
}
                
