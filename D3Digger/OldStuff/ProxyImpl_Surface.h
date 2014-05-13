#pragma once

#include "ProxyImpl.h"

struct ProxyImplSurface
    : ProxyBase<IDirect3DSurface9>
{
    typedef IDirect3DSurface9 IBase;
    typedef ProxyBase<IBase> MyProxyBase;

    ProxyImplSurface(IBase *pimpl);

    HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE UnlockRect() override;

public:
    void invalidate() override;

private:
    TextureProxyPtr getTexture(HRESULT *out = nullptr);
};

template<>
struct ProxyImplHelper<IDirect3DSurface9>
{
    typedef ProxyImplSurface Type;
};
