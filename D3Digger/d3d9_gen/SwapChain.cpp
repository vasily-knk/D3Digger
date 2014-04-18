#include "SwapChain.h"

namespace D3Digger
{
namespace D3D9
{
namespace SwapChain
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
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags)
{
    return pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion, dwFlags);
}

HRESULT ProxyBase::GetFrontBufferData(IDirect3DSurface9* pDestSurface)
{
    return pimpl_->GetFrontBufferData(pDestSurface);
}

HRESULT ProxyBase::GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    return pimpl_->GetBackBuffer(iBackBuffer, Type, ppBackBuffer);
}

HRESULT ProxyBase::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
    return pimpl_->GetRasterStatus(pRasterStatus);
}

HRESULT ProxyBase::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
    return pimpl_->GetDisplayMode(pMode);
}

HRESULT ProxyBase::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase::GetPresentParameters(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return pimpl_->GetPresentParameters(pPresentationParameters);
}

IBasePtr ProxyBase::getPImpl() const
{
    return pimpl_;
}

} // namespace D3Digger

} // namespace D3D9

} // namespace SwapChain


