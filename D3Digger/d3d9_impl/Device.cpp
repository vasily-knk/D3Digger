#include "stdafx.h"
#include "D3D.h"
#include "Device.h"
#include "Texture.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

ProxyImplPtr ProxyImpl::create(IBasePtr pimpl)
{
    return ProxyImplPtr(new ProxyImpl(pimpl));
}

ProxyImpl::ProxyImpl(IBasePtr pimpl)
    : ProxyBase(pimpl)
{

}

ProxyImpl::~ProxyImpl()
{
    assert(!ProxyBase::getPImpl());
}


ULONG ProxyImpl::Release() 
{
    auto refcount = ProxyBase::Release();
    if (refcount == 0)
        detach_signal_();

    return refcount;
}

HRESULT ProxyImpl::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    auto res = ProxyBase::CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);

    if (ppTexture && SUCCEEDED(res) && *ppTexture)
    {
        Texture::ProxyImplPtr child = Texture::ProxyImpl::create(*ppTexture);
        keeper_.addChild(child);
        *ppTexture = child.get();
    }

    return res;
}


HRESULT ProxyImpl::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    auto res = ProxyBase::GetTexture(Stage, ppTexture);
    if (SUCCEEDED(res) && ppTexture)
    {
        assert(*ppTexture);
        if (isTexture(*ppTexture))
        {
            assert(Stage < textures_.size());

            Texture::ProxyImplPtr tex = textures_.at(Stage);
            assert(tex);
            assert(tex->getPImpl() == *ppTexture);

            *ppTexture = tex.get();
        }
    }

    return res;
}

HRESULT ProxyImpl::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    Texture::ProxyImplPtr tex;
    if (pTexture && isTexture(pTexture))
    {
        Texture::ProxyImpl *temp_ptr = dynamic_cast<Texture::ProxyImpl *>(pTexture);
        assert(temp_ptr);
        tex = temp_ptr->getShared();
        pTexture = tex->getPImpl();
    }

    auto res = ProxyBase::SetTexture(Stage, pTexture);
    if (SUCCEEDED(res))
    {
        if (Stage >= textures_.size())
            textures_.resize(Stage + 1);

        textures_.at(Stage) = tex;
    }

    return res;
}

bool ProxyImpl::isTexture(IDirect3DBaseTexture9* pTexture) const
{
    return pTexture->GetType() == D3DRTYPE_TEXTURE;
}



} // namespace Device

} // namespace D3D9

} // namespace D3Digger
