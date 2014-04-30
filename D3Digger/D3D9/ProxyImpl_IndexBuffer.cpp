#include "stdafx.h"
#include "ProxyImpl_IndexBuffer.h"

template<>
IProxyPtr<IDirect3DIndexBuffer9>::Type createProxy<IDirect3DIndexBuffer9>(IDirect3DIndexBuffer9 *pimpl)
{
    return IProxyPtr<IDirect3DIndexBuffer9>::Type(new ProxyImplIndexBuffer(pimpl));
}

ProxyImplIndexBuffer::ProxyImplIndexBuffer(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
{

}