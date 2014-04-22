#include "stdafx.h"
#include "ProxyImpl_Texture.h"

template<>
shared_ptr<IProxy<IDirect3DTexture9>> createProxy<IDirect3DTexture9>(IDirect3DTexture9 *pimpl)
{
    return make_shared<ProxyImplTexture>(pimpl);
}

ProxyImplTexture::ProxyImplTexture(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
    , saved_(true)
{

}

void ProxyImplTexture::save()
{
    if (!saved_)
    {
        stringstream ss;
        ss << "D:\\Textures\\0x" << pimpl_ << ".png";
        LOG("Saving texture: " << ss.str());

        D3DXSaveTextureToFileA(ss.str().c_str(), D3DXIFF_PNG, pimpl_, nullptr);

        saved_ = true;
    }
}
