#pragma once

#include "IProxyExt.h"

template<typename T>
struct IProxy;

template<typename T>
struct IProxyPtr
{
    typedef intrusive_ptr<IProxy<T>> Type;
    typedef IProxy<T> *RawType;
};

template<typename T>
typename IProxyPtr<T>::RawType createProxy(T *pimpl);

#include "undef.h"

#define MY_BEGIN_INTERFACE_(name, parent)   \
    template<> struct IProxy<name>;         \
    template<>                              \
    typename IProxyPtr<name>::RawType createProxy(name *pimpl); \
                                            \
    template<>                              \
    struct IProxy<name>                     \
        : name, IProxyExt<name>, IProxy<parent> \
    {                                       \
        virtual name *getPImpl() = 0;       \
        virtual size_t addExtRef() = 0;
      
#define MY_BEGIN_INTERFACE(name)            \
    template<> struct IProxy<name>;         \
    template<>                              \
    typename IProxyPtr<name>::RawType createProxy(name *pimpl); \
                                            \
    template<>                              \
    struct IProxy<name>                     \
        : name, IProxyExt<name>, Interface  \
    {                                       \
        virtual name *getPImpl() = 0;       \
        virtual size_t addExtRef() = 0;

#define MY_END_INTERFACE }

#define MY_STDMETHOD_(ret_type, name, args) virtual ret_type STDMETHODCALLTYPE name args = 0
#define MY_STDMETHOD(name, args) MY_STDMETHOD_(HRESULT, name, args)

#define MY_PURE

#include "decl.h"
#include "undef.h"

inline void intrusive_ptr_add_ref(IProxy<IUnknown> *ptr)
{
    ptr->AddRef();
}

inline void intrusive_ptr_release(IProxy<IUnknown> *ptr)
{
    ptr->Release();
}
