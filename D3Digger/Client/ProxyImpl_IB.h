#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DIndexBuffer9>
    : ProxyBase<IDirect3DIndexBuffer9>
{
    typedef ProxyBase<IDirect3DIndexBuffer9> Base;

    ProxyImpl(ProxyId id); 

    HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE Unlock() override;

private:
    size_t getSize();

private:
    struct LockData
    {
        size_t offset;
        DWORD flags;
        shared_ptr<vector<uint8_t>> buffer;
    };
    
    std::stack<LockData> lockStack_;
    size_t size_;
};

} // namespace Client

} // namespace D3D9