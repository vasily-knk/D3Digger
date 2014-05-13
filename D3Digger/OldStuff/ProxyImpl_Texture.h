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

public:
    void invalidate() override;
    optional<int> lastUpdateFrame() const override { return lastUpdateFrame_; };

private:
    void updateLockStats(size_t size);
    DeviceProxyPtr getDevice();
    SurfaceProxyPtr getSurfaceLevel(UINT Level, HRESULT *out = nullptr);

private:
    optional<int> lastUpdateFrame_;
};

template<>
struct ProxyImplHelper<IDirect3DTexture9>
{
    typedef ProxyImplTexture Type;
};