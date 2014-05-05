#include "stdafx.h"
#include "ProxyImpl_Surface.h"
#include "ProxyImpl_Device.h"


namespace
{
size_t bytesPerPixel(D3DFORMAT format)
{
    switch (format)
    {
    case D3DFMT_R8G8B8               : return 3;
    case D3DFMT_A8R8G8B8             : return 4;
    case D3DFMT_X8R8G8B8             : return 4;
    case D3DFMT_R5G6B5               : return 2;
    case D3DFMT_X1R5G5B5             : return 2;
    case D3DFMT_A1R5G5B5             : return 2;
    case D3DFMT_A4R4G4B4             : return 2;
    case D3DFMT_R3G3B2               : return 1;
    case D3DFMT_A8                   : return 1;
    case D3DFMT_A8R3G3B2             : return 2;
    case D3DFMT_X4R4G4B4             : return 2;
    case D3DFMT_A2B10G10R10          : return 4;
    case D3DFMT_A8B8G8R8             : return 4;
    case D3DFMT_X8B8G8R8             : return 4;
    case D3DFMT_G16R16               : return 4;
    case D3DFMT_A2R10G10B10          : return 4;
    case D3DFMT_A16B16G16R16         : return 8;
    case D3DFMT_A8P8                 : return 2;
    case D3DFMT_P8                   : return 1;
    case D3DFMT_L8                   : return 1;
    case D3DFMT_A8L8                 : return 2;
    case D3DFMT_A4L4                 : return 1;
    case D3DFMT_V8U8                 : return 2;
    case D3DFMT_L6V5U5               : return 2;
    case D3DFMT_X8L8V8U8             : return 4;
    case D3DFMT_Q8W8V8U8             : return 4;
    case D3DFMT_V16U16               : return 4;
    case D3DFMT_A2W10V10U10          : return 4;
    case D3DFMT_UYVY                 : return 0;
    case D3DFMT_R8G8_B8G8            : return 4;
    case D3DFMT_YUY2                 : return 0;
    case D3DFMT_G8R8_G8B8            : return 4;
    case D3DFMT_DXT1                 : return 0;
    case D3DFMT_DXT2                 : return 0;
    case D3DFMT_DXT3                 : return 0;
    case D3DFMT_DXT4                 : return 0;
    case D3DFMT_DXT5                 : return 0;
    case D3DFMT_D16_LOCKABLE         : return 2;
    case D3DFMT_D32                  : return 4;
    case D3DFMT_D15S1                : return 2;
    case D3DFMT_D24S8                : return 4;
    case D3DFMT_D24X8                : return 4;
    case D3DFMT_D24X4S4              : return 4;
    case D3DFMT_D16                  : return 2;
    case D3DFMT_D32F_LOCKABLE        : return 4;
    case D3DFMT_D24FS8               : return 4;

    case D3DFMT_L16                  : return 2;
    case D3DFMT_VERTEXDATA           : return 0;
    case D3DFMT_INDEX16              : return 2;
    case D3DFMT_INDEX32              : return 4;
    case D3DFMT_Q16W16V16U16         : return 8;
    case D3DFMT_MULTI2_ARGB8         : return 0;
    case D3DFMT_R16F                 : return 2;
    case D3DFMT_G16R16F              : return 4;
    case D3DFMT_A16B16G16R16F        : return 8;
    case D3DFMT_R32F                 : return 4;
    case D3DFMT_G32R32F              : return 8;
    case D3DFMT_A32B32G32R32F        : return 16;
    case D3DFMT_CxV8U8               : return 0;
    default: return 0;
    }
    return 0;
}

}


ProxyImplSurface::ProxyImplSurface(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{
    D3DSURFACE_DESC desc;
    HRESULT res = GetDesc(&desc);
    assert(SUCCEEDED(res));
    if (SUCCEEDED(res))
    {
        static set<D3DFORMAT> unsupported;
        
        size_t b = bytesPerPixel(desc.Format);
        if (b == 0 && !unsupported.count(desc.Format))
        {
            unsupported.insert(desc.Format);
            char letters[5];
            letters[4] = 0;
            memcpy(letters, &desc.Format, 4);
            LOG("Unsupported surface format: " << desc.Format << ": " << letters);
        }
    }
}

HRESULT ProxyImplSurface::LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return MyProxyBase::LockRect(pLockedRect, pRect, Flags);
}

HRESULT ProxyImplSurface::UnlockRect()
{
    invalidate();
    return MyProxyBase::UnlockRect();
}

TextureProxyPtr ProxyImplSurface::getTexture(HRESULT *out)
{
    void *p = nullptr;
    HRESULT res = pimpl_->GetContainer(IID_IDirect3DTexture9, &p);
    if (out)
        *out = res;

    if (!SUCCEEDED(res) || !p)
        return TextureProxyPtr();
    else
        return wrapProxySmart(reinterpret_cast<IDirect3DTexture9*>(p));
}

void ProxyImplSurface::invalidate()
{
    auto tex = getTexture();
    if (tex)
        tex->invalidate();
}
