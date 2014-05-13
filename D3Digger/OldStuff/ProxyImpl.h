#pragma once

#include "ProxyBase.h"

typedef IProxyPtr<IDirect3DTexture9>::RawType TextureProxyRawPtr;
typedef IProxyPtr<IDirect3DSurface9>::RawType SurfaceProxyRawPtr;

typedef IProxyPtr<IDirect3DDevice9>::Type DeviceProxyPtr;
typedef IProxyPtr<IDirect3DTexture9>::Type TextureProxyPtr;
typedef IProxyPtr<IDirect3DSurface9>::Type SurfaceProxyPtr;


template<typename T>
struct ProxyImplHelper;

