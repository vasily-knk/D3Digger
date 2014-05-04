#include "stdafx.h"
#include "ProxyImpl_Texture.h"
#include "ProxyImpl_Surface.h"
#include "ProxyImpl_Device.h"


ProxyImplTexture::ProxyImplTexture(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{

}

HRESULT ProxyImplTexture::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    HRESULT res;
    auto surf = getSurfaceLevel(Level, &res);
    if (!surf)
        return res;

    return surf->LockRect(pLockedRect, pRect, Flags);
}

HRESULT ProxyImplTexture::UnlockRect(UINT Level)
{
    HRESULT res;
    auto surf = getSurfaceLevel(Level, &res);
    if (!surf)
        return res;
    
    return surf->UnlockRect();
}


DeviceProxyPtr ProxyImplTexture::getDevice() 
{
    IDirect3DDevice9 *d = nullptr;
    pimpl_->GetDevice(&d);
    auto dev = wrapProxySmart(d);

    assert(dev);
    return dev;
}

void ProxyImplTexture::invalidate()
{
    lastUpdateFrame_ = getDevice()->getCurrentFrame();
}

SurfaceProxyPtr ProxyImplTexture::getSurfaceLevel(UINT Level, HRESULT *out)
{
    IDirect3DSurface9 *p = nullptr;
    HRESULT res = pimpl_->GetSurfaceLevel(Level, &p);
    if (out)
        *out = res;

    if (!SUCCEEDED(res) || !p)
        return SurfaceProxyPtr();
    else
        return wrapProxySmart(p);
}
