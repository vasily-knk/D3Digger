#pragma once

template<typename T>
struct IProxy;

template<typename T>
shared_ptr<IProxy<T>> createProxy();

#include "undef.h"

#define MY_BEGIN_INTERFACE_(name, parent)   \
    template<> struct IProxy<name>;         \
    template<>                              \
    shared_ptr<IProxy<name>> createProxy(); \
                                            \
    template<>                              \
    struct IProxy<name>                     \
        : name, IProxy<parent>              \
    {                                       \
        virtual name *getPImpl() = 0;
      
#define MY_BEGIN_INTERFACE(name)            \
    template<> struct IProxy<name>;         \
    template<>                              \
    shared_ptr<IProxy<name>> createProxy(); \
                                            \
    template<>                              \
    struct IProxy<name>                     \
        : name, Interface                   \
    {                                       \
        virtual name *getPImpl() = 0;

#define MY_END_INTERFACE }

#define MY_STDMETHOD_(ret_type, name, args) virtual ret_type STDMETHODCALLTYPE name args = 0
#define MY_STDMETHOD(name, args) MY_STDMETHOD_(HRESULT, name, args)

#define MY_PURE

#include "decl.h"
#include "undef.h"

