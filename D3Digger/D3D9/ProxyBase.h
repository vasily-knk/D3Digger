#pragma once

#include "d3d9/IProxy.h"
#include "d3d9/wrap.h"

template<typename T>
struct ProxyBase;

void logMethod(const char *interfaceName, const char *methodName);

void LogQI(REFIID);

template<typename T>
inline T checkReturn(T const &val, const char *interfaceName, const char *methodName)
{
    (void)interfaceName;
    (void)methodName;
    return val;
}
/*

template<>
HRESULT checkReturn(HRESULT const &val, const char *interfaceName, const char *methodName);*/


#define MY_BEGIN_INTERFACE(name) \
    template<> \
    struct ProxyBase<name> \
        : IProxy<name> \
    { \
        typedef name IBase; \
        IBase *getPImpl() override; \
        size_t addExtRef() override; \
        ProxyBase(IBase *pimpl);

#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)

#define MY_END_INTERFACE \
protected: \
    IBase *pimpl_; \
    size_t extRefCount_; \
    bool goingToDie_; \
    size_t refCount_; \
    bool innerRefCountLocked_; \
}

#define MY_STDMETHOD(name, args) HRESULT STDMETHODCALLTYPE name args override
#define MY_STDMETHOD_(ret_type, name, args) ret_type STDMETHODCALLTYPE name args override

#define MY_PURE

#include "common/interface.h"
#include "d3d9/decl.h"
#include "d3d9/undef.h"
