#include "stdafx.h"

#include "d3d9/wrap.h"

void fuck(IDirect3DTexture9 *tex)
{
    typedef IDirect3DTexture9 IBase;
    typedef IProxy<IBase> IProxy;
    typedef shared_ptr<IProxy> IProxyPtr;

    IProxyPtr proxy = wrapProxy(tex);
    tex = unwrapProxy<IBase>(proxy.get());
}