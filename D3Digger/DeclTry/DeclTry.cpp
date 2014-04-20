#include "stdafx.h"

#include "proxy.h"
#include "pimpl.h"

struct ProxyImpl_Texture
    : IPImplHandler_IDirect3DTexture9
{

};

void foo()
{
    ProxyImpl_Texture impl;
}