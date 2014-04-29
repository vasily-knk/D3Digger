#include "stdafx.h"
#include "ProxyImpl_IndexBuffer.h"

template<>
shared_ptr<IProxy<IDirect3DIndexBuffer9>> createProxy<IDirect3DIndexBuffer9>(IDirect3DIndexBuffer9 *pimpl)
{
    return make_shared<ProxyImplIndexBuffer>(pimpl);
}

ProxyImplIndexBuffer::ProxyImplIndexBuffer(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{

}