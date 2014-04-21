#pragma once

#include "IProxy.h"
#include "Global.h"

template<typename T>
inline shared_ptr<IProxy<T>> wrapProxy(T *p)
{
    typedef T IBase;
    auto id = static_cast<IUnknown*>(p);
    if (getGlobal().mapping.count(id) == 0)
    {
        auto v = make_pair(id, createProxy<IBase>());
        getGlobal().mapping.insert(v);
        //getGlobal().mapping[id] = createProxy<IBase>();
    }

    shared_ptr<IProxy<IBase>> proxy = dynamic_pointer_cast<IProxy<IBase>>(getGlobal().mapping.at(id));
    return proxy;
}

template<typename T>
inline T *unwrapProxy(T *p)
{
    typedef T IBase;
    IProxy<IBase> *proxy = dynamic_cast<IProxy<IBase> *>(p);
    return proxy->getPImpl();
}