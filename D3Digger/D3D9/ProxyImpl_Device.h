#pragma once

#include "ProxyImpl.h"

struct ProxyImplDevice
    : ProxyBase<IDirect3DDevice9>
{
    typedef IDirect3DDevice9 IBase;

    ProxyImplDevice(IBase *pimpl);
    HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture) override;
};