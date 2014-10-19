#pragma once

#include "IProxy.h"
#include "Global.h"

template<typename T>
inline typename IProxyPtr<T>::RawType wrapProxy(T *p)
{
    typedef T IBase;
    auto id = static_cast<IUnknown*>(p);

    auto &mapping = getGlobal().proxyMapping();

    if (mapping.count(id) == 0)
    {
        IProxyPtr<IBase>::RawType proxy = createProxy<IBase>(p);
        mapping.insert(make_pair(id, IProxyPtr<IBase>::Type(proxy, true)));
        return proxy;
    }
    else
    {
        IProxyPtr<IUnknown>::RawType ptr = mapping.at(id).get();
        ptr->addExtRef();
        return dynamic_cast<IProxy<T> *>(ptr);
    }
}

template<typename T>
inline typename IProxyPtr<T>::Type wrapProxySmart(T *p)
{
    typename IProxyPtr<T>::RawType raw = wrapProxy(p);
    return typename IProxyPtr<T>::Type(raw, false);
}

template<typename T>
inline T *unwrapProxy(T *p)
{
    typedef T IBase;
    IProxy<IBase> *proxy = dynamic_cast<IProxy<IBase> *>(p);
    return proxy->getPImpl();
}

inline void detachProxy(IUnknown *id)
{
    getGlobal().proxyMapping().erase(id);
}

