#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DVertexBuffer9>
    : ProxyBase<IDirect3DVertexBuffer9>
{
    typedef ProxyBase<IDirect3DVertexBuffer9> Base;

    ProxyImpl(ProxyId id); 

    HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE Unlock() override;

private:
    size_t getSize();

private:
    struct LockData
    {
        size_t offset, size;
        DWORD flags;
    };
    
    optional<LockData> lockData_;
    vector<uint8_t> buffer_;
};

} // namespace Client

} // namespace D3D9