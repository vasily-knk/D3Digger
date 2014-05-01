#pragma once

#include "ProxyImpl.h"

struct ProxyImplTexture
    : ProxyBase<IDirect3DTexture9>
{
    typedef IDirect3DTexture9 IBase;
    typedef ProxyBase<IBase> MyProxyBase;
    
    ProxyImplTexture(IBase *pimpl);

    HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level) override;

};

template<>
struct ProxyImplHelper<IDirect3DTexture9>
{
    typedef ProxyImplTexture Type;
};