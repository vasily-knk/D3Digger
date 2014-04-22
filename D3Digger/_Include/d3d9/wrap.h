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
        auto v = make_pair(id, createProxy<IBase>(p));
        getGlobal().mapping.insert(v);
    }
    else
    {
        getGlobal().mapping.at(id)->addExtRef();
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

inline void detachProxy(IUnknown *id)
{
    //getGlobal().mapping.erase(id);
}