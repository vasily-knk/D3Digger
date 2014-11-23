#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DSurface9>
    : ProxyBase<IDirect3DSurface9>
{
    typedef ProxyBase<IDirect3DSurface9> Base;

    ProxyImpl(ProxyId id); 

    HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE UnlockRect() override;

private:
    size_t calcBufferOffset(RECT const &rect) const;
    size_t calcPitch() const;
    RECT calcRect(RECT const *src_rect) const;

private:
    D3DSURFACE_DESC desc_;
    vector<char> buffer_;
    size_t bytesPerPixel_;

    struct LockData
    {
        RECT rect;
        DWORD flags;
    };

    optional<LockData> lockData_;
};


} // namespace Client

} // namespace D3D9