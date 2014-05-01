#pragma once

#include "ProxyImpl.h"

struct ProxyImplIndexBuffer
    : ProxyBase<IDirect3DIndexBuffer9>
{
    typedef IDirect3DIndexBuffer9 IBase;

    ProxyImplIndexBuffer(IBase *pimpl);
};

template<>
struct ProxyImplHelper<IDirect3DIndexBuffer9>
{
    typedef ProxyImplIndexBuffer Type;
};