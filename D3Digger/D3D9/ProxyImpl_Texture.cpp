#include "stdafx.h"
#include "ProxyImpl_Texture.h"
#include "ProxyImpl_Device.h"


ProxyImplTexture::ProxyImplTexture(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{

}

HRESULT ProxyImplTexture::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return MyProxyBase::LockRect(Level, pLockedRect, pRect, Flags);
}

HRESULT ProxyImplTexture::UnlockRect(UINT Level)
{
    return MyProxyBase::UnlockRect(Level);
}


ProxyImplDevicePtr ProxyImplTexture::getDevice() 
{
    IDirect3DDevice9 *d = nullptr;
    pimpl_->GetDevice(&d);
    auto dev = dynamic_pointer_cast<ProxyImplDevice>(wrapProxySmart(d));

    assert(dev);
    return dev;
}

void ProxyImplTexture::updateLockStats(size_t size)
{
    auto dev = getDevice();
    dev->appendTexLock(size);
}
