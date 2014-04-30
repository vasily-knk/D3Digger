#pragma once

#include "ProxyImpl.h"

struct ProxyImplDevice;

struct ProxyImplVertexBuffer
    : ProxyBase<IDirect3DVertexBuffer9>
{
    typedef IDirect3DVertexBuffer9 IBase;
    typedef ProxyBase<IDirect3DVertexBuffer9> MyProxyBase;

    ProxyImplVertexBuffer(IBase *pimpl);

    HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE Unlock() override;

    optional<int> lastLockFrame() const { return lastLockFrame_; }
    bool isLocked() const { return lock_.is_initialized(); }

    size_t getSize() const;

private:
    void updateLockStats(size_t size);
    ProxyImplDevicePtr getDevice();
    void initDevice();

private:
    vector<uint8_t> buffer_;
    optional<int> lastLockFrame_;

    struct LockType
    {
        explicit LockType(bool real)
            : real(real) 
        {

        }
        bool real;
    };

    optional<LockType> lock_;
};
