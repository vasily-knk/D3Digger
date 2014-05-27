#pragma once

#include "common/signals.h"

namespace D3D9
{
	namespace Client
	{
		typedef uint32_t ProxyId;
	
		template<typename T>
		struct IProxyExt
		{

		};

		template<>
		struct IProxyExt<IUnknown>
		{
			virtual ProxyId getId() = 0;
			DECLARE_SIGNAL(Deleted, ());
		};

		template<typename T>
		struct IProxy;

		/*template<typename T>
		struct IProxyPtr
		{
			typedef intrusive_ptr<IProxy<T>> Type;
			typedef IProxy<T> *RawType;
		};*/

#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE_(name, parent)   \
		template<>                              \
		struct IProxy<name>                     \
			: name, IProxyExt<name>, IProxy<parent> \
		{                                       


#define MY_BEGIN_INTERFACE(name)            \
		template<>                              \
		struct IProxy<name>                     \
			: name, IProxyExt<name>, Interface  \
		{                                       

#define MY_END_INTERFACE };

#define MY_STDMETHOD_(ret_type, name, args) virtual ret_type STDMETHODCALLTYPE name args = 0;
#define MY_STDMETHOD(name, args) MY_STDMETHOD_(HRESULT, name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"

	} // namespace Client

} // namespace D3D9