#include "stdafx.h"
#include "ProxyImpl.h"


#define FOR_X(X) \
    X(IDirect3D9                 ) \
    X(IDirect3DSwapChain9        ) \
    X(IDirect3DSurface9          ) \
    X(IDirect3DVolumeTexture9    ) \
    X(IDirect3DCubeTexture9      ) \
    X(IDirect3DStateBlock9       ) \
    X(IDirect3DVertexDeclaration9) \
    X(IDirect3DVertexShader9     ) \
    X(IDirect3DPixelShader9      ) \
    X(IDirect3DQuery9            ) \
    X(IDirect3DVolume9           ) 

#define CREATE_PROXY_DEFINITION(name) \
    template<> \
    IProxyPtr<name>::Type createProxy<name>(name *pimpl) \
    { \
        return IProxyPtr<name>::Type(new ProxyBase<name>(pimpl)); \
    }

FOR_X(CREATE_PROXY_DEFINITION)

#undef CREATE_PROXY_DEFINITION
#undef FOR_X

template<>
IProxyPtr<IDirect3DBaseTexture9>::Type createProxy<IDirect3DBaseTexture9>(IDirect3DBaseTexture9 *pimpl)
{
    assert(false);
    (void)pimpl;
    return IProxyPtr<IDirect3DBaseTexture9>::Type();
}

