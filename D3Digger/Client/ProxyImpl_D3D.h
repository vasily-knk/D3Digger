#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3D9>
    : ProxyBase<IDirect3D9>
{
    typedef ProxyBase<IDirect3D9> Base;

    ProxyImpl(ProxyId id); 
    ~ProxyImpl(); 
};

} // namespace Client

} // namespace D3D9