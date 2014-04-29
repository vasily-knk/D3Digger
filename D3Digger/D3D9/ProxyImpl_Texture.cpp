#include "stdafx.h"
#include "ProxyImpl_Texture.h"

template<>
shared_ptr<IProxy<IDirect3DTexture9>> createProxy<IDirect3DTexture9>(IDirect3DTexture9 *pimpl)
{
    return make_shared<ProxyImplTexture>(pimpl);
}

ProxyImplTexture::ProxyImplTexture(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
    , saved_(false)
{

}

void ProxyImplTexture::save()
{
    return;

}
