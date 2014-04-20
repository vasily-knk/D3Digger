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
        IResPtr tex = extractShared(*ppTexture);
        if (tex)
        {
            //assert(tex->getPImpl() == *ppTexture);
            *ppTexture = tex.get();
        }
    }

    return res;
}

HRESULT ProxyImpl::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    Texture::ProxyImplPtr tex;
    if (pTexture)
    {
        tex = extractShared(pTexture);
        if (tex)
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


IResPtr ProxyImpl::extractShared(IDirect3DBaseTexture9* pTexture) const
{
    D3DRESOURCETYPE type = pTexture->GetType();
    switch(type)
    {
    case D3DRTYPE_TEXTURE:
        IResShare *resShare = dynamic_cast<IResShare *>(pTexture);
        assert(resShare);
        return resShare->getSharedRes();
        break;
    case D3DRTYPE_VOLUMETEXTURE:
    case D3DRTYPE_CUBETEXTURE:
        // not implemented yet
        return IResPtr();
        break;
    default:
    }

    assert(false);
}

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
