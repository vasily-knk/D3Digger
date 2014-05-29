#pragma once

#include "common/interface.h"
#include "d3d9/InterfacesList.h"

namespace D3D9
{

namespace Server
{

typedef uint32_t ProxyId;

struct IProcMap;
typedef shared_ptr<IProcMap> IProcMapPtr;

IProcMapPtr createProcMap();		

struct IProcMap 
    : Interface
{
    virtual ProxyId getProxyID(IUnknown *ptr) = 0;
    virtual IUnknown *getPtrImpl(ProxyId id) = 0;

	template<typename T>
	T *getPtr(ProxyId id)
	{
        IUnknown *p = getPtrImpl(id);
        assert(p);

        GUID guid = getGuid<T>();
        T* dst;
        HRESULT res = p->QueryInterface(guid, reinterpret_cast<void**>(&dst));
        assert(SUCCEEDED(res));
        assert(dst);

        if (SUCCEEDED(res) && dst)
            p->Release();

        return dst;
	}

private:
    template<typename T>
    static GUID getGuid();

#define IPROCMAP_GUID(name) \
    template<> \
    static GUID getGuid<name>() \
    { \
        return IID_##name; \
    }

    D3D9_LIST_INTERFACES(IPROCMAP_GUID)

#undef IPROCMAP_GUID        


};

} // namespace Server

} // namespace D3D9