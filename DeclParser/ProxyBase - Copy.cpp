#include "stdafx.h"
#include "ProxyBase.h"
            
template<>
shared_ptr<IProxy<IDirect3D9>> createProxy<IDirect3D9>(IDirect3D9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3D9>>(pimpl);
}
            
ProxyBase<IDirect3D9>::ProxyBase(IDirect3D9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3D9 *ProxyBase<IDirect3D9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3D9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3D9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3D9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::RegisterSoftwareDevice(void* pInitializeFunction)
{
   
   auto res = pimpl_->RegisterSoftwareDevice(pInitializeFunction);
   
   return res;
                    
}
                
UINT ProxyBase<IDirect3D9>::GetAdapterCount()
{
   
   auto res = pimpl_->GetAdapterCount();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
   
   auto res = pimpl_->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
   
   return res;
                    
}
                
UINT ProxyBase<IDirect3D9>::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
   
   auto res = pimpl_->GetAdapterModeCount(Adapter, Format);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
   
   auto res = pimpl_->EnumAdapterModes(Adapter, Format, Mode, pMode);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
   
   auto res = pimpl_->GetAdapterDisplayMode(Adapter, pMode);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
   
   auto res = pimpl_->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
   
   auto res = pimpl_->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
   
   auto res = pimpl_->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
   
   auto res = pimpl_->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
   
   auto res = pimpl_->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
   
   auto res = pimpl_->GetDeviceCaps(Adapter, DeviceType, pCaps);
   
   return res;
                    
}
                
HMONITOR ProxyBase<IDirect3D9>::GetAdapterMonitor(UINT Adapter)
{
   
   auto res = pimpl_->GetAdapterMonitor(Adapter);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3D9>::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
   
   auto res = pimpl_->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
   *ppReturnedDeviceInterface = wrapProxy<IDirect3DDevice9>(*ppReturnedDeviceInterface).get();
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DDevice9>> createProxy<IDirect3DDevice9>(IDirect3DDevice9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DDevice9>>(pimpl);
}
            
ProxyBase<IDirect3DDevice9>::ProxyBase(IDirect3DDevice9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DDevice9 *ProxyBase<IDirect3DDevice9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DDevice9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DDevice9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DDevice9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::TestCooperativeLevel()
{
   
   auto res = pimpl_->TestCooperativeLevel();
   
   return res;
                    
}
                
UINT ProxyBase<IDirect3DDevice9>::GetAvailableTextureMem()
{
   
   auto res = pimpl_->GetAvailableTextureMem();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::EvictManagedResources()
{
   
   auto res = pimpl_->EvictManagedResources();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDirect3D(IDirect3D9** ppD3D9)
{
   
   auto res = pimpl_->GetDirect3D(ppD3D9);
   *ppD3D9 = wrapProxy<IDirect3D9>(*ppD3D9).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDeviceCaps(D3DCAPS9* pCaps)
{
   
   auto res = pimpl_->GetDeviceCaps(pCaps);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
   
   auto res = pimpl_->GetDisplayMode(iSwapChain, pMode);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
   
   auto res = pimpl_->GetCreationParameters(pParameters);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
   pCursorBitmap = unwrapProxy<IDirect3DSurface9>(pCursorBitmap);
   auto res = pimpl_->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
   
   return res;
                    
}
                
void ProxyBase<IDirect3DDevice9>::SetCursorPosition(int X, int Y, DWORD Flags)
{
   
   pimpl_->SetCursorPosition(X, Y, Flags);
   
   ;
                    
}
                
BOOL ProxyBase<IDirect3DDevice9>::ShowCursor(BOOL bShow)
{
   
   auto res = pimpl_->ShowCursor(bShow);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
   
   auto res = pimpl_->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
   *pSwapChain = wrapProxy<IDirect3DSwapChain9>(*pSwapChain).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
   
   auto res = pimpl_->GetSwapChain(iSwapChain, pSwapChain);
   *pSwapChain = wrapProxy<IDirect3DSwapChain9>(*pSwapChain).get();
   return res;
                    
}
                
UINT ProxyBase<IDirect3DDevice9>::GetNumberOfSwapChains()
{
   
   auto res = pimpl_->GetNumberOfSwapChains();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
   
   auto res = pimpl_->Reset(pPresentationParameters);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion)
{
   
   auto res = pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
   
   auto res = pimpl_->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
   *ppBackBuffer = wrapProxy<IDirect3DSurface9>(*ppBackBuffer).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
   
   auto res = pimpl_->GetRasterStatus(iSwapChain, pRasterStatus);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetDialogBoxMode(BOOL bEnableDialogs)
{
   
   auto res = pimpl_->SetDialogBoxMode(bEnableDialogs);
   
   return res;
                    
}
                
void ProxyBase<IDirect3DDevice9>::SetGammaRamp(UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP* pRamp)
{
   
   pimpl_->SetGammaRamp(iSwapChain, Flags, pRamp);
   
   ;
                    
}
                
void ProxyBase<IDirect3DDevice9>::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
   
   pimpl_->GetGammaRamp(iSwapChain, pRamp);
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
   *ppTexture = wrapProxy<IDirect3DTexture9>(*ppTexture).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
   *ppVolumeTexture = wrapProxy<IDirect3DVolumeTexture9>(*ppVolumeTexture).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
   *ppCubeTexture = wrapProxy<IDirect3DCubeTexture9>(*ppCubeTexture).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
   *ppVertexBuffer = wrapProxy<IDirect3DVertexBuffer9>(*ppVertexBuffer).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
   *ppIndexBuffer = wrapProxy<IDirect3DIndexBuffer9>(*ppIndexBuffer).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
   *ppSurface = wrapProxy<IDirect3DSurface9>(*ppSurface).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
   *ppSurface = wrapProxy<IDirect3DSurface9>(*ppSurface).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::UpdateSurface(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, const POINT* pDestPoint)
{
   pSourceSurface = unwrapProxy<IDirect3DSurface9>(pSourceSurface); pDestinationSurface = unwrapProxy<IDirect3DSurface9>(pDestinationSurface);
   auto res = pimpl_->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
   pSourceTexture = unwrapProxy<IDirect3DBaseTexture9>(pSourceTexture); pDestinationTexture = unwrapProxy<IDirect3DBaseTexture9>(pDestinationTexture);
   auto res = pimpl_->UpdateTexture(pSourceTexture, pDestinationTexture);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
   pRenderTarget = unwrapProxy<IDirect3DSurface9>(pRenderTarget); pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);
   auto res = pimpl_->GetRenderTargetData(pRenderTarget, pDestSurface);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
   pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);
   auto res = pimpl_->GetFrontBufferData(iSwapChain, pDestSurface);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::StretchRect(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestSurface, const RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
   pSourceSurface = unwrapProxy<IDirect3DSurface9>(pSourceSurface); pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);
   auto res = pimpl_->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::ColorFill(IDirect3DSurface9* pSurface, const RECT* pRect, D3DCOLOR color)
{
   pSurface = unwrapProxy<IDirect3DSurface9>(pSurface);
   auto res = pimpl_->ColorFill(pSurface, pRect, color);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
   
   auto res = pimpl_->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
   *ppSurface = wrapProxy<IDirect3DSurface9>(*ppSurface).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
   pRenderTarget = unwrapProxy<IDirect3DSurface9>(pRenderTarget);
   auto res = pimpl_->SetRenderTarget(RenderTargetIndex, pRenderTarget);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
   
   auto res = pimpl_->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
   *ppRenderTarget = wrapProxy<IDirect3DSurface9>(*ppRenderTarget).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
   pNewZStencil = unwrapProxy<IDirect3DSurface9>(pNewZStencil);
   auto res = pimpl_->SetDepthStencilSurface(pNewZStencil);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
   
   auto res = pimpl_->GetDepthStencilSurface(ppZStencilSurface);
   *ppZStencilSurface = wrapProxy<IDirect3DSurface9>(*ppZStencilSurface).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::BeginScene()
{
   
   auto res = pimpl_->BeginScene();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::EndScene()
{
   
   auto res = pimpl_->EndScene();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::Clear(DWORD Count, const D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
   
   auto res = pimpl_->Clear(Count, pRects, Flags, Color, Z, Stencil);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix)
{
   
   auto res = pimpl_->SetTransform(State, pMatrix);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
   
   auto res = pimpl_->GetTransform(State, pMatrix);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::MultiplyTransform(D3DTRANSFORMSTATETYPE unnamed0, const D3DMATRIX* unnamed1)
{
   
   auto res = pimpl_->MultiplyTransform(unnamed0, unnamed1);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetViewport(const D3DVIEWPORT9* pViewport)
{
   
   auto res = pimpl_->SetViewport(pViewport);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetViewport(D3DVIEWPORT9* pViewport)
{
   
   auto res = pimpl_->GetViewport(pViewport);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetMaterial(const D3DMATERIAL9* pMaterial)
{
   
   auto res = pimpl_->SetMaterial(pMaterial);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetMaterial(D3DMATERIAL9* pMaterial)
{
   
   auto res = pimpl_->GetMaterial(pMaterial);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetLight(DWORD Index, const D3DLIGHT9* unnamed0)
{
   
   auto res = pimpl_->SetLight(Index, unnamed0);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetLight(DWORD Index, D3DLIGHT9* unnamed0)
{
   
   auto res = pimpl_->GetLight(Index, unnamed0);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::LightEnable(DWORD Index, BOOL Enable)
{
   
   auto res = pimpl_->LightEnable(Index, Enable);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetLightEnable(DWORD Index, BOOL* pEnable)
{
   
   auto res = pimpl_->GetLightEnable(Index, pEnable);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetClipPlane(DWORD Index, const float* pPlane)
{
   
   auto res = pimpl_->SetClipPlane(Index, pPlane);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetClipPlane(DWORD Index, float* pPlane)
{
   
   auto res = pimpl_->GetClipPlane(Index, pPlane);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
   
   auto res = pimpl_->SetRenderState(State, Value);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
   
   auto res = pimpl_->GetRenderState(State, pValue);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
   
   auto res = pimpl_->CreateStateBlock(Type, ppSB);
   *ppSB = wrapProxy<IDirect3DStateBlock9>(*ppSB).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::BeginStateBlock()
{
   
   auto res = pimpl_->BeginStateBlock();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
   
   auto res = pimpl_->EndStateBlock(ppSB);
   *ppSB = wrapProxy<IDirect3DStateBlock9>(*ppSB).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetClipStatus(const D3DCLIPSTATUS9* pClipStatus)
{
   
   auto res = pimpl_->SetClipStatus(pClipStatus);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
   
   auto res = pimpl_->GetClipStatus(pClipStatus);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
   
   auto res = pimpl_->GetTexture(Stage, ppTexture);
   *ppTexture = wrapProxy<IDirect3DBaseTexture9>(*ppTexture).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
   pTexture = unwrapProxy<IDirect3DBaseTexture9>(pTexture);
   auto res = pimpl_->SetTexture(Stage, pTexture);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
   
   auto res = pimpl_->GetTextureStageState(Stage, Type, pValue);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
   
   auto res = pimpl_->SetTextureStageState(Stage, Type, Value);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
   
   auto res = pimpl_->GetSamplerState(Sampler, Type, pValue);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
   
   auto res = pimpl_->SetSamplerState(Sampler, Type, Value);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::ValidateDevice(DWORD* pNumPasses)
{
   
   auto res = pimpl_->ValidateDevice(pNumPasses);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY* pEntries)
{
   
   auto res = pimpl_->SetPaletteEntries(PaletteNumber, pEntries);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
   
   auto res = pimpl_->GetPaletteEntries(PaletteNumber, pEntries);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetCurrentTexturePalette(UINT PaletteNumber)
{
   
   auto res = pimpl_->SetCurrentTexturePalette(PaletteNumber);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetCurrentTexturePalette(UINT* PaletteNumber)
{
   
   auto res = pimpl_->GetCurrentTexturePalette(PaletteNumber);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetScissorRect(const RECT* pRect)
{
   
   auto res = pimpl_->SetScissorRect(pRect);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetScissorRect(RECT* pRect)
{
   
   auto res = pimpl_->GetScissorRect(pRect);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetSoftwareVertexProcessing(BOOL bSoftware)
{
   
   auto res = pimpl_->SetSoftwareVertexProcessing(bSoftware);
   
   return res;
                    
}
                
BOOL ProxyBase<IDirect3DDevice9>::GetSoftwareVertexProcessing()
{
   
   auto res = pimpl_->GetSoftwareVertexProcessing();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetNPatchMode(float nSegments)
{
   
   auto res = pimpl_->SetNPatchMode(nSegments);
   
   return res;
                    
}
                
float ProxyBase<IDirect3DDevice9>::GetNPatchMode()
{
   
   auto res = pimpl_->GetNPatchMode();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
   
   auto res = pimpl_->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitive(D3DPRIMITIVETYPE unnamed0, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
   
   auto res = pimpl_->DrawIndexedPrimitive(unnamed0, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
   
   auto res = pimpl_->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, const void* pIndexData, D3DFORMAT IndexDataFormat, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
   
   auto res = pimpl_->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
   pDestBuffer = unwrapProxy<IDirect3DVertexBuffer9>(pDestBuffer); pVertexDecl = unwrapProxy<IDirect3DVertexDeclaration9>(pVertexDecl);
   auto res = pimpl_->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
   
   auto res = pimpl_->CreateVertexDeclaration(pVertexElements, ppDecl);
   *ppDecl = wrapProxy<IDirect3DVertexDeclaration9>(*ppDecl).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
   pDecl = unwrapProxy<IDirect3DVertexDeclaration9>(pDecl);
   auto res = pimpl_->SetVertexDeclaration(pDecl);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
   
   auto res = pimpl_->GetVertexDeclaration(ppDecl);
   *ppDecl = wrapProxy<IDirect3DVertexDeclaration9>(*ppDecl).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetFVF(DWORD FVF)
{
   
   auto res = pimpl_->SetFVF(FVF);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetFVF(DWORD* pFVF)
{
   
   auto res = pimpl_->GetFVF(pFVF);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateVertexShader(const DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
   
   auto res = pimpl_->CreateVertexShader(pFunction, ppShader);
   *ppShader = wrapProxy<IDirect3DVertexShader9>(*ppShader).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShader(IDirect3DVertexShader9* pShader)
{
   pShader = unwrapProxy<IDirect3DVertexShader9>(pShader);
   auto res = pimpl_->SetVertexShader(pShader);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
   
   auto res = pimpl_->GetVertexShader(ppShader);
   *ppShader = wrapProxy<IDirect3DVertexShader9>(*ppShader).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
   
   auto res = pimpl_->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
   
   auto res = pimpl_->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
   
   auto res = pimpl_->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
   
   auto res = pimpl_->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
   
   auto res = pimpl_->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
   
   auto res = pimpl_->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
   pStreamData = unwrapProxy<IDirect3DVertexBuffer9>(pStreamData);
   auto res = pimpl_->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
   
   auto res = pimpl_->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
   *ppStreamData = wrapProxy<IDirect3DVertexBuffer9>(*ppStreamData).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetStreamSourceFreq(UINT StreamNumber, UINT Setting)
{
   
   auto res = pimpl_->SetStreamSourceFreq(StreamNumber, Setting);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting)
{
   
   auto res = pimpl_->GetStreamSourceFreq(StreamNumber, pSetting);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
   pIndexData = unwrapProxy<IDirect3DIndexBuffer9>(pIndexData);
   auto res = pimpl_->SetIndices(pIndexData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
   
   auto res = pimpl_->GetIndices(ppIndexData);
   *ppIndexData = wrapProxy<IDirect3DIndexBuffer9>(*ppIndexData).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreatePixelShader(const DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
   
   auto res = pimpl_->CreatePixelShader(pFunction, ppShader);
   *ppShader = wrapProxy<IDirect3DPixelShader9>(*ppShader).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShader(IDirect3DPixelShader9* pShader)
{
   pShader = unwrapProxy<IDirect3DPixelShader9>(pShader);
   auto res = pimpl_->SetPixelShader(pShader);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
   
   auto res = pimpl_->GetPixelShader(ppShader);
   *ppShader = wrapProxy<IDirect3DPixelShader9>(*ppShader).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
   
   auto res = pimpl_->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
   
   auto res = pimpl_->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
   
   auto res = pimpl_->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
   
   auto res = pimpl_->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::SetPixelShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
   
   auto res = pimpl_->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
   
   auto res = pimpl_->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawRectPatch(UINT Handle, const float* pNumSegs, const D3DRECTPATCH_INFO* pRectPatchInfo)
{
   
   auto res = pimpl_->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DrawTriPatch(UINT Handle, const float* pNumSegs, const D3DTRIPATCH_INFO* pTriPatchInfo)
{
   
   auto res = pimpl_->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::DeletePatch(UINT Handle)
{
   
   auto res = pimpl_->DeletePatch(Handle);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DDevice9>::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
   
   auto res = pimpl_->CreateQuery(Type, ppQuery);
   *ppQuery = wrapProxy<IDirect3DQuery9>(*ppQuery).get();
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DStateBlock9>> createProxy<IDirect3DStateBlock9>(IDirect3DStateBlock9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DStateBlock9>>(pimpl);
}
            
ProxyBase<IDirect3DStateBlock9>::ProxyBase(IDirect3DStateBlock9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DStateBlock9 *ProxyBase<IDirect3DStateBlock9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DStateBlock9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DStateBlock9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DStateBlock9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DStateBlock9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DStateBlock9>::Capture()
{
   
   auto res = pimpl_->Capture();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DStateBlock9>::Apply()
{
   
   auto res = pimpl_->Apply();
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DSwapChain9>> createProxy<IDirect3DSwapChain9>(IDirect3DSwapChain9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DSwapChain9>>(pimpl);
}
            
ProxyBase<IDirect3DSwapChain9>::ProxyBase(IDirect3DSwapChain9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DSwapChain9 *ProxyBase<IDirect3DSwapChain9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DSwapChain9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DSwapChain9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DSwapChain9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion, DWORD dwFlags)
{
   
   auto res = pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion, dwFlags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetFrontBufferData(IDirect3DSurface9* pDestSurface)
{
   pDestSurface = unwrapProxy<IDirect3DSurface9>(pDestSurface);
   auto res = pimpl_->GetFrontBufferData(pDestSurface);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
   
   auto res = pimpl_->GetBackBuffer(iBackBuffer, Type, ppBackBuffer);
   *ppBackBuffer = wrapProxy<IDirect3DSurface9>(*ppBackBuffer).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
   
   auto res = pimpl_->GetRasterStatus(pRasterStatus);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
   
   auto res = pimpl_->GetDisplayMode(pMode);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSwapChain9>::GetPresentParameters(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
   
   auto res = pimpl_->GetPresentParameters(pPresentationParameters);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DVertexDeclaration9>> createProxy<IDirect3DVertexDeclaration9>(IDirect3DVertexDeclaration9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DVertexDeclaration9>>(pimpl);
}
            
ProxyBase<IDirect3DVertexDeclaration9>::ProxyBase(IDirect3DVertexDeclaration9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DVertexDeclaration9 *ProxyBase<IDirect3DVertexDeclaration9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVertexDeclaration9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DVertexDeclaration9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DVertexDeclaration9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexDeclaration9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexDeclaration9>::GetDeclaration(D3DVERTEXELEMENT9* pElement, UINT* pNumElements)
{
   
   auto res = pimpl_->GetDeclaration(pElement, pNumElements);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DVertexShader9>> createProxy<IDirect3DVertexShader9>(IDirect3DVertexShader9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DVertexShader9>>(pimpl);
}
            
ProxyBase<IDirect3DVertexShader9>::ProxyBase(IDirect3DVertexShader9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DVertexShader9 *ProxyBase<IDirect3DVertexShader9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVertexShader9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DVertexShader9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DVertexShader9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexShader9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexShader9>::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
   
   auto res = pimpl_->GetFunction(unnamed0, pSizeOfData);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DPixelShader9>> createProxy<IDirect3DPixelShader9>(IDirect3DPixelShader9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DPixelShader9>>(pimpl);
}
            
ProxyBase<IDirect3DPixelShader9>::ProxyBase(IDirect3DPixelShader9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DPixelShader9 *ProxyBase<IDirect3DPixelShader9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DPixelShader9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DPixelShader9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DPixelShader9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DPixelShader9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DPixelShader9>::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
   
   auto res = pimpl_->GetFunction(unnamed0, pSizeOfData);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DTexture9>> createProxy<IDirect3DTexture9>(IDirect3DTexture9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DTexture9>>(pimpl);
}
            
ProxyBase<IDirect3DTexture9>::ProxyBase(IDirect3DTexture9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DTexture9 *ProxyBase<IDirect3DTexture9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DTexture9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DTexture9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::SetPriority(DWORD PriorityNew)
{
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::GetPriority()
{
   
   auto res = pimpl_->GetPriority();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DTexture9>::PreLoad()
{
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DTexture9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::SetLOD(DWORD LODNew)
{
   
   auto res = pimpl_->SetLOD(LODNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::GetLOD()
{
   
   auto res = pimpl_->GetLOD();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DTexture9>::GetLevelCount()
{
   
   auto res = pimpl_->GetLevelCount();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
   
   auto res = pimpl_->SetAutoGenFilterType(FilterType);
   
   return res;
                    
}
                
D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DTexture9>::GetAutoGenFilterType()
{
   
   auto res = pimpl_->GetAutoGenFilterType();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DTexture9>::GenerateMipSubLevels()
{
   
   pimpl_->GenerateMipSubLevels();
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
   
   auto res = pimpl_->GetLevelDesc(Level, pDesc);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel)
{
   
   auto res = pimpl_->GetSurfaceLevel(Level, ppSurfaceLevel);
   *ppSurfaceLevel = wrapProxy<IDirect3DSurface9>(*ppSurfaceLevel).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
   
   auto res = pimpl_->LockRect(Level, pLockedRect, pRect, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::UnlockRect(UINT Level)
{
   
   auto res = pimpl_->UnlockRect(Level);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DTexture9>::AddDirtyRect(const RECT* pDirtyRect)
{
   
   auto res = pimpl_->AddDirtyRect(pDirtyRect);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DVolumeTexture9>> createProxy<IDirect3DVolumeTexture9>(IDirect3DVolumeTexture9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DVolumeTexture9>>(pimpl);
}
            
ProxyBase<IDirect3DVolumeTexture9>::ProxyBase(IDirect3DVolumeTexture9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DVolumeTexture9 *ProxyBase<IDirect3DVolumeTexture9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVolumeTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DVolumeTexture9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DVolumeTexture9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::SetPriority(DWORD PriorityNew)
{
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::GetPriority()
{
   
   auto res = pimpl_->GetPriority();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DVolumeTexture9>::PreLoad()
{
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DVolumeTexture9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::SetLOD(DWORD LODNew)
{
   
   auto res = pimpl_->SetLOD(LODNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::GetLOD()
{
   
   auto res = pimpl_->GetLOD();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVolumeTexture9>::GetLevelCount()
{
   
   auto res = pimpl_->GetLevelCount();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
   
   auto res = pimpl_->SetAutoGenFilterType(FilterType);
   
   return res;
                    
}
                
D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DVolumeTexture9>::GetAutoGenFilterType()
{
   
   auto res = pimpl_->GetAutoGenFilterType();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DVolumeTexture9>::GenerateMipSubLevels()
{
   
   pimpl_->GenerateMipSubLevels();
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetLevelDesc(UINT Level, D3DVOLUME_DESC* pDesc)
{
   
   auto res = pimpl_->GetLevelDesc(Level, pDesc);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::GetVolumeLevel(UINT Level, IDirect3DVolume9** ppVolumeLevel)
{
   
   auto res = pimpl_->GetVolumeLevel(Level, ppVolumeLevel);
   *ppVolumeLevel = wrapProxy<IDirect3DVolume9>(*ppVolumeLevel).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::LockBox(UINT Level, D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
   
   auto res = pimpl_->LockBox(Level, pLockedVolume, pBox, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::UnlockBox(UINT Level)
{
   
   auto res = pimpl_->UnlockBox(Level);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolumeTexture9>::AddDirtyBox(const D3DBOX* pDirtyBox)
{
   
   auto res = pimpl_->AddDirtyBox(pDirtyBox);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DCubeTexture9>> createProxy<IDirect3DCubeTexture9>(IDirect3DCubeTexture9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DCubeTexture9>>(pimpl);
}
            
ProxyBase<IDirect3DCubeTexture9>::ProxyBase(IDirect3DCubeTexture9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DCubeTexture9 *ProxyBase<IDirect3DCubeTexture9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DCubeTexture9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DCubeTexture9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DCubeTexture9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::SetPriority(DWORD PriorityNew)
{
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::GetPriority()
{
   
   auto res = pimpl_->GetPriority();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DCubeTexture9>::PreLoad()
{
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DCubeTexture9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::SetLOD(DWORD LODNew)
{
   
   auto res = pimpl_->SetLOD(LODNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::GetLOD()
{
   
   auto res = pimpl_->GetLOD();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DCubeTexture9>::GetLevelCount()
{
   
   auto res = pimpl_->GetLevelCount();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
   
   auto res = pimpl_->SetAutoGenFilterType(FilterType);
   
   return res;
                    
}
                
D3DTEXTUREFILTERTYPE ProxyBase<IDirect3DCubeTexture9>::GetAutoGenFilterType()
{
   
   auto res = pimpl_->GetAutoGenFilterType();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DCubeTexture9>::GenerateMipSubLevels()
{
   
   pimpl_->GenerateMipSubLevels();
   
   ;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
   
   auto res = pimpl_->GetLevelDesc(Level, pDesc);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9** ppCubeMapSurface)
{
   
   auto res = pimpl_->GetCubeMapSurface(FaceType, Level, ppCubeMapSurface);
   *ppCubeMapSurface = wrapProxy<IDirect3DSurface9>(*ppCubeMapSurface).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
   
   auto res = pimpl_->LockRect(FaceType, Level, pLockedRect, pRect, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level)
{
   
   auto res = pimpl_->UnlockRect(FaceType, Level);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DCubeTexture9>::AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT* pDirtyRect)
{
   
   auto res = pimpl_->AddDirtyRect(FaceType, pDirtyRect);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DVertexBuffer9>> createProxy<IDirect3DVertexBuffer9>(IDirect3DVertexBuffer9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DVertexBuffer9>>(pimpl);
}
            
ProxyBase<IDirect3DVertexBuffer9>::ProxyBase(IDirect3DVertexBuffer9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DVertexBuffer9 *ProxyBase<IDirect3DVertexBuffer9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVertexBuffer9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DVertexBuffer9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DVertexBuffer9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVertexBuffer9>::SetPriority(DWORD PriorityNew)
{
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DVertexBuffer9>::GetPriority()
{
   
   auto res = pimpl_->GetPriority();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DVertexBuffer9>::PreLoad()
{
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DVertexBuffer9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
   
   auto res = pimpl_->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::Unlock()
{
   
   auto res = pimpl_->Unlock();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVertexBuffer9>::GetDesc(D3DVERTEXBUFFER_DESC* pDesc)
{
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DIndexBuffer9>> createProxy<IDirect3DIndexBuffer9>(IDirect3DIndexBuffer9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DIndexBuffer9>>(pimpl);
}
            
ProxyBase<IDirect3DIndexBuffer9>::ProxyBase(IDirect3DIndexBuffer9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DIndexBuffer9 *ProxyBase<IDirect3DIndexBuffer9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DIndexBuffer9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DIndexBuffer9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DIndexBuffer9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DIndexBuffer9>::SetPriority(DWORD PriorityNew)
{
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DIndexBuffer9>::GetPriority()
{
   
   auto res = pimpl_->GetPriority();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DIndexBuffer9>::PreLoad()
{
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DIndexBuffer9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
   
   auto res = pimpl_->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::Unlock()
{
   
   auto res = pimpl_->Unlock();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DIndexBuffer9>::GetDesc(D3DINDEXBUFFER_DESC* pDesc)
{
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DSurface9>> createProxy<IDirect3DSurface9>(IDirect3DSurface9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DSurface9>>(pimpl);
}
            
ProxyBase<IDirect3DSurface9>::ProxyBase(IDirect3DSurface9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DSurface9 *ProxyBase<IDirect3DSurface9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DSurface9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DSurface9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DSurface9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DSurface9>::SetPriority(DWORD PriorityNew)
{
   
   auto res = pimpl_->SetPriority(PriorityNew);
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DSurface9>::GetPriority()
{
   
   auto res = pimpl_->GetPriority();
   
   return res;
                    
}
                
void ProxyBase<IDirect3DSurface9>::PreLoad()
{
   
   pimpl_->PreLoad();
   
   ;
                    
}
                
D3DRESOURCETYPE ProxyBase<IDirect3DSurface9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetContainer(REFIID riid, void** ppContainer)
{
   
   auto res = pimpl_->GetContainer(riid, ppContainer);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetDesc(D3DSURFACE_DESC* pDesc)
{
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
   
   auto res = pimpl_->LockRect(pLockedRect, pRect, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::UnlockRect()
{
   
   auto res = pimpl_->UnlockRect();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::GetDC(HDC* phdc)
{
   
   auto res = pimpl_->GetDC(phdc);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DSurface9>::ReleaseDC(HDC hdc)
{
   
   auto res = pimpl_->ReleaseDC(hdc);
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DVolume9>> createProxy<IDirect3DVolume9>(IDirect3DVolume9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DVolume9>>(pimpl);
}
            
ProxyBase<IDirect3DVolume9>::ProxyBase(IDirect3DVolume9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DVolume9 *ProxyBase<IDirect3DVolume9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DVolume9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DVolume9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DVolume9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
   
   auto res = pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
   
   auto res = pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::FreePrivateData(REFGUID refguid)
{
   
   auto res = pimpl_->FreePrivateData(refguid);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetContainer(REFIID riid, void** ppContainer)
{
   
   auto res = pimpl_->GetContainer(riid, ppContainer);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::GetDesc(D3DVOLUME_DESC* pDesc)
{
   
   auto res = pimpl_->GetDesc(pDesc);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::LockBox(D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
   
   auto res = pimpl_->LockBox(pLockedVolume, pBox, Flags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DVolume9>::UnlockBox()
{
   
   auto res = pimpl_->UnlockBox();
   
   return res;
                    
}
                
template<>
shared_ptr<IProxy<IDirect3DQuery9>> createProxy<IDirect3DQuery9>(IDirect3DQuery9 *pimpl)
{
    return make_shared<ProxyBase<IDirect3DQuery9>>(pimpl);
}
            
ProxyBase<IDirect3DQuery9>::ProxyBase(IDirect3DQuery9 *pimpl)
    : pimpl_(pimpl)
    , extRefCount_(1)
{
}
            
IDirect3DQuery9 *ProxyBase<IDirect3DQuery9>::getPImpl()
{
    return pimpl_;
}
            
HRESULT ProxyBase<IDirect3DQuery9>::QueryInterface(REFIID riid, void** ppvObj)
{
    assert(false); // Not implemented
    return E_FAIL;
                    
}
                
ULONG ProxyBase<IDirect3DQuery9>::AddRef()
{
    auto refCount = pimpl_->AddRef();
    ++extRefCount_;
    return refCount;
                    
}
                
ULONG ProxyBase<IDirect3DQuery9>::Release()
{
    auto refCount = pimpl_->Release();
    --extRefCount_;
    if (extRefCount_ == 0)
    {
        detachProxy(pimpl_);
        pimpl_ = nullptr;
    }
    return refCount;
                    
}
                
HRESULT ProxyBase<IDirect3DQuery9>::GetDevice(IDirect3DDevice9** ppDevice)
{
   
   auto res = pimpl_->GetDevice(ppDevice);
   *ppDevice = wrapProxy<IDirect3DDevice9>(*ppDevice).get();
   return res;
                    
}
                
D3DQUERYTYPE ProxyBase<IDirect3DQuery9>::GetType()
{
   
   auto res = pimpl_->GetType();
   
   return res;
                    
}
                
DWORD ProxyBase<IDirect3DQuery9>::GetDataSize()
{
   
   auto res = pimpl_->GetDataSize();
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DQuery9>::Issue(DWORD dwIssueFlags)
{
   
   auto res = pimpl_->Issue(dwIssueFlags);
   
   return res;
                    
}
                
HRESULT ProxyBase<IDirect3DQuery9>::GetData(void* pData, DWORD dwSize, DWORD dwGetDataFlags)
{
   
   auto res = pimpl_->GetData(pData, dwSize, dwGetDataFlags);
   
   return res;
                    
}
                
