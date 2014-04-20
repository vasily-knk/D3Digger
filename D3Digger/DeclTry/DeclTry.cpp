#include "stdafx.h"

#include "d3d9/proxy.h"

struct ProxyImpl_Texture
    : IDirect3DTexture9
{

};

void foo()
{
    ProxyImpl_Texture impl;
}