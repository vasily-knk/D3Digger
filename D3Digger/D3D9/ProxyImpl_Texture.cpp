#include "stdafx.h"
#include "ProxyImpl_Texture.h"
#include "ProxyImpl_Device.h"


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


