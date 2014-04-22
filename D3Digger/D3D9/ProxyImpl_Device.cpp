#include "stdafx.h"
#include "ProxyImpl_Device.h"
#include "ProxyImpl_Texture.h"

template<>
shared_ptr<IProxy<IDirect3DDevice9>> createProxy<IDirect3DDevice9>(IDirect3DDevice9 *pimpl)
{
    return make_shared<ProxyImplDevice>(pimpl);
}

ProxyImplDevice::ProxyImplDevice(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{

}

HRESULT ProxyImplDevice::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    logMethod("ProxyImplDevice", "SetTexture");
    if (pTexture) 
    {
        if (pTexture->GetType() == D3DRTYPE_TEXTURE)
        {
            auto impl = dynamic_cast<ProxyImplTexture*>(pTexture);
            assert(impl);
            impl->save();
        }
        pTexture = unwrapProxy<IDirect3DBaseTexture9>(pTexture);
    }

    auto res = pimpl_->SetTexture(Stage, pTexture);
    return res;
}

