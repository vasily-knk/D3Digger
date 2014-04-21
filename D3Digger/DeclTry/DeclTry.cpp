#include "stdafx.h"

#include "../d3d9_gen/ProxyBase.h"
#include "pimpl.h"
#include "shared.h"

struct ProxyImpl_Texture
    : ProxyBase_IDirect3DTexture9
    , IPImplHandler_IDirect3DTexture9
    , IShared_IDirect3DTexture9
    , enable_shared_from_this<ProxyImpl_Texture>
{
    typedef ProxyImpl_Texture Self;
    typedef ProxyBase_IDirect3DTexture9 Base;
    typedef Base::IBase IBase;


    ProxyImpl_Texture(IBase *pimpl)
        : Base(pimpl)
    {

    }

    IBase *getPImpl() override
    {
        return pimpl_;
    }

    shared_ptr<IUnknown             > getShared_IUnknown             () override { return shared_from_this(); }
    shared_ptr<IDirect3DResource9   > getShared_IDirect3DResource9   () override { return shared_from_this(); }
    shared_ptr<IDirect3DBaseTexture9> getShared_IDirect3DBaseTexture9() override { return shared_from_this(); }
    shared_ptr<IDirect3DTexture9    > getShared_IDirect3DTexture9    () override { return shared_from_this(); }
};

void foo()
{
    ProxyImpl_Texture impl(nullptr);
}