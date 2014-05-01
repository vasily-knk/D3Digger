#include "stdafx.h"
#include "ProxyImpl_Texture.h"
#include "ProxyImpl_Device.h"

template<>
IProxyPtr<IDirect3DTexture9>::Type createProxy<IDirect3DTexture9>(IDirect3DTexture9 *pimpl)
{
    return IProxyPtr<IDirect3DTexture9>::Type(new ProxyImplTexture(pimpl), true);
}

ProxyImplTexture::ProxyImplTexture(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{

}

HRESULT ProxyImplTexture::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return MyProxyBase::LockRect(Level, pLockedRect, pRect, Flags);
}

HRESULT ProxyImplTexture::UnlockRect(UINT Level)
{
    return MyProxyBase::UnlockRect(Level);
}


