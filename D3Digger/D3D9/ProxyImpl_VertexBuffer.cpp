#include "stdafx.h"
#include "ProxyImpl_VertexBuffer.h"
#include "ProxyImpl_Device.h"

template<>
IProxyPtr<IDirect3DVertexBuffer9>::Type createProxy<IDirect3DVertexBuffer9>(IDirect3DVertexBuffer9 *pimpl)
{
    return IProxyPtr<IDirect3DVertexBuffer9>::Type(new ProxyImplVertexBuffer(pimpl), true);
}

ProxyImplVertexBuffer::ProxyImplVertexBuffer(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
    , buffer_(getSize())
{
}

HRESULT ProxyImplVertexBuffer::Lock(UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags)
{
    auto dev = getDevice();
    int currentFrame = dev->getCurrentFrame();
    optional<int> lastAllowedLockedFrame = dev->getLastAllowedLockFrame();

    lastLockFrame_ = currentFrame;

    bool doLock = !lastAllowedLockedFrame || *lastAllowedLockedFrame >= currentFrame;

    size_t realSize = SizeToLock != 0 ? SizeToLock : getSize();

    if ((Flags & D3DLOCK_READONLY) == 0)
        updateLockStats(realSize);
    
    assert(!lock_);
    
    if (doLock)
    {
        lock_ = LockType(true);
        return MyProxyBase::Lock(OffsetToLock, SizeToLock, ppbData, Flags);
    }
    else
    {
        lock_ = LockType(false);
        assert(buffer_.size() >= realSize);

//         MyProxyBase::Lock(OffsetToLock, SizeToLock, ppbData, Flags);
//         uint8_t *data = reinterpret_cast<uint8_t>(*ppbData);
//         std::copy(data, data + realSize, buffer_.begin());

        *ppbData = &buffer_[0];
        return D3D_OK;
    }
}

HRESULT STDMETHODCALLTYPE ProxyImplVertexBuffer::Unlock()
{
    assert(lastLockFrame_);
    assert(lock_);

    LockType const &lock = *lock_;
    
    HRESULT res = D3D_OK;
    if (lock.real)
        res = MyProxyBase::Unlock();

    lock_.reset();
    
    return res;
}

void ProxyImplVertexBuffer::updateLockStats(size_t size)
{
    auto dev = getDevice();
    dev->appendVBLock(size);
}

ProxyImplDevicePtr ProxyImplVertexBuffer::getDevice() 
{
    IDirect3DDevice9 *d = nullptr;
    MyProxyBase::GetDevice(&d);
    auto dev = ProxyImplDevicePtr(dynamic_cast<ProxyImplDevice*>(d));

    assert(dev);
    return dev;
}

size_t ProxyImplVertexBuffer::getSize() const
{
    D3DVERTEXBUFFER_DESC desc;
    pimpl_->GetDesc(&desc);
    return desc.Size;
}

void ProxyImplVertexBuffer::initDevice()
{
/*
    IDirect3DDevice9 *d = nullptr;
    MyProxyBase::GetDevice(&d);
    device_ = ProxyImplDevicePtr(dynamic_cast<ProxyImplDevice*>(d));

    assert(device_);
*/
}
