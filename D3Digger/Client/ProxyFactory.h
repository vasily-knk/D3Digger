#pragma once

#include "d3d9/IProxy.h"

namespace D3D9
{
	namespace Client
	{

		template<typename T>
		IProxy<T> *createProxy(ProxyId id);

#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE(name) template<> IProxy<name> *createProxy(ProxyId id);
#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)
#define MY_END_INTERFACE 
#define MY_STDMETHOD_(ret_type, name, args)
#define MY_STDMETHOD(name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"

	} // namespace Client

} // namespace D3D9