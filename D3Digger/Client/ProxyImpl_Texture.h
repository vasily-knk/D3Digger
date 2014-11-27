#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DTexture9>
    : ProxyBase<IDirect3DTexture9>
{
    typedef ProxyBase<IDirect3DTexture9> Base;

    ProxyImpl(ProxyId id); 
    ~ProxyImpl();

    // STDMETHODCALLTYPE
    HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel);
    
    HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags);
    HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level);
    HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc);

private:
    vector<IDirect3DSurface9*> surfaces_;
};

} // namespace Client

} // namespace D3D9