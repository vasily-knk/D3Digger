#pragma once

#include "common/bytes.h"
#include "IProxy.h"
#include "IGlobal.h"
#include "d3d9/Methods.h"


namespace D3D9
{
	namespace Client
	{
	
		template<typename T>
		struct ProxyBase;


#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE(name) \
		template<> \
		struct ProxyBase<name> \
	        : IProxy<name> \
	    { \
			typedef name IBase; \
			ProxyId getId() override { return id_; }; \
			DEFINE_SIGNAL(Deleted, ()); \
			ProxyBase(ProxyId id); 

#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)

#define MY_END_INTERFACE \
		private: \
			ProxyId id_; \
			int refcount_; \
		};

#define MY_STDMETHOD(name, args) HRESULT STDMETHODCALLTYPE name args override;
#define MY_STDMETHOD_(ret_type, name, args) ret_type STDMETHODCALLTYPE name args override;

#include "d3d9/decl.h"
#include "d3d9/undef.h"

	} // namespace Client

} // namespace D3D9