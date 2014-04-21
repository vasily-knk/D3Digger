#pragma once

#define MY_BEGIN_INTERFACE(name) \
    struct ProxyBase_##name : name, Interface { \
        typedef name IBase; \
        ProxyBase_##name(IBase *pimpl);

#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)

#define MY_END_INTERFACE \
    protected: \
        IBase *pimpl_; \
    }

#define MY_STDMETHOD(name, args) HRESULT STDMETHODCALLTYPE name args override
#define MY_STDMETHOD_(ret_type, name, args) ret_type STDMETHODCALLTYPE name args override

#define MY_PURE

#include "common/interface.h"
#include "d3d9/decl.h"
#include "d3d9/undef.h"