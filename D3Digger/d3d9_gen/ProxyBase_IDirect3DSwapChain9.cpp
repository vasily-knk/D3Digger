#include "ProxyBase.h"


ProxyBase_IDirect3DSwapChain9::ProxyBase_IDirect3DSwapChain9(IDirect3DSwapChain9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DSwapChain9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DSwapChain9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DSwapChain9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DSwapChain9::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags)
{
    return pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion, dwFlags);
}

HRESULT ProxyBase_IDirect3DSwapChain9::GetFrontBufferData(IDirect3DSurface9* pDestSurface)
{
    return pimpl_->GetFrontBufferData(pDestSurface);
}

HRESULT ProxyBase_IDirect3DSwapChain9::GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    return pimpl_->GetBackBuffer(iBackBuffer, Type, ppBackBuffer);
}

HRESULT ProxyBase_IDirect3DSwapChain9::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
    return pimpl_->GetRasterStatus(pRasterStatus);
}

HRESULT ProxyBase_IDirect3DSwapChain9::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
    return pimpl_->GetDisplayMode(pMode);
}

HRESULT ProxyBase_IDirect3DSwapChain9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DSwapChain9::GetPresentParameters(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return pimpl_->GetPresentParameters(pPresentationParameters);
}


