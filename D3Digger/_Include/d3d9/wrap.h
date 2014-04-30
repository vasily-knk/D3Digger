#pragma once

#include "IProxy.h"
#include "Global.h"

template<typename T>
inline typename IProxyPtr<T>::Type wrapProxy(T *p)
{
    typedef T IBase;
    auto id = static_cast<IUnknown*>(p);

    auto &mapping = getGlobal().proxyMapping();

    if (mapping.count(id) == 0)
    {
        auto v = make_pair(id, createProxy<IBase>(p));
        mapping.insert(v);
    }

    IProxyPtr<IBase>::Type proxy = dynamic_pointer_cast<IProxy<IBase>>(mapping.at(id));
    return proxy;
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