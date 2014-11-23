#include "stdafx.h"
#include "ProxyImpl_D3D.h"


namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3D9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
{
    
}

Impl::~ProxyImpl()
{
    deleteGlobal();
}

} // namespace Client

} // namespace D3D9