#pragma once

#include "common/bytes.h"
#include "d3d9/Client/IProxy.h"
#include "IGlobal.h"
#include "d3d9/Methods.h"
#include "d3d9/structs_refl.h"


namespace D3D9
{
	namespace Client
	{

        typedef HRESULT HRESULT_SYNC;

	
		template<typename T>
		struct ProxyBase;

        struct guid_cmp
        {
            bool operator()(GUID const &r1, GUID const &r2) const
            {
                typedef std::tuple<uint32_t, uint16_t, uint16_t, uint64_t> Tuple;
                Tuple t1(r1.Data1, r1.Data2, r1.Data3, *(reinterpret_cast<uint64_t const*>(r1.Data4)));
                Tuple t2(r2.Data1, r2.Data2, r2.Data3, *(reinterpret_cast<uint64_t const*>(r2.Data4)));
                return t1 < t2;
            }
        };
        
        typedef std::map<GUID, vector<char>, guid_cmp> ProxyPrivateData;


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
            ProxyPrivateData privateData_; \
		};

#define MY_STDMETHOD(name, args) HRESULT STDMETHODCALLTYPE name args override;
#define MY_STDMETHOD_(ret_type, name, args) ret_type STDMETHODCALLTYPE name args override;

#include "d3d9/decl.h"
#include "d3d9/undef.h"

	} // namespace Client

} // namespace D3D9