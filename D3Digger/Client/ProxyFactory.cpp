#include "stdafx.h"
#include "ProxyFactory.h"
#include "ProxyBase.h"

#include "ProxyImpl_Device.h"
#include "ProxyImpl_VB.h"
#include "ProxyImpl_Surface.h"

namespace D3D9
{
	namespace Client
	{

#define FOR_X(X) \
    X(IDirect3D9                 ) \
    X(IDirect3DSwapChain9        ) \
    X(IDirect3DVolumeTexture9    ) \
    X(IDirect3DCubeTexture9      ) \
    X(IDirect3DStateBlock9       ) \
    X(IDirect3DVertexDeclaration9) \
    X(IDirect3DVertexShader9     ) \
    X(IDirect3DPixelShader9      ) \
    X(IDirect3DQuery9            ) \
    X(IDirect3DVolume9           ) \
    X(IDirect3DTexture9          ) \
    X(IDirect3DIndexBuffer9      ) 

#define CREATE_PROXY_DEFINITION(name) \
    template<> \
    IProxy<name> *createProxy(ProxyId id) \
    { \
        return new ProxyBase<name>(id); \
    }

FOR_X(CREATE_PROXY_DEFINITION)

#undef CREATE_PROXY_DEFINITION
#undef FOR_X

#define FOR_X(X) \
    X(IDirect3DDevice9) \
    X(IDirect3DVertexBuffer9) \
    X(IDirect3DSurface9)

#define CREATE_PROXY_DEFINITION(name) \
    template<> \
    IProxy<name> *createProxy(ProxyId id) \
    { \
        return new ProxyImpl<name>(id); \
    }

FOR_X(CREATE_PROXY_DEFINITION)

#undef CREATE_PROXY_DEFINITION
#undef FOR_X



template<> 
		IProxy<IDirect3DBaseTexture9> *createProxy(ProxyId id) 
		{ 
	        return nullptr; 
	    }

	} // namespace Client

} // namespace D3D9