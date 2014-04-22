#pragma once

#include "ProxyImpl.h"

struct ProxyImplTexture
    : ProxyBase<IDirect3DTexture9>
{
    typedef IDirect3DTexture9 IBase;
    
    ProxyImplTexture(IBase *pimpl);
    void save();

private:
    bool saved_;
};