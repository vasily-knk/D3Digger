#pragma once

#define MY_BEGIN_INTERFACE(name) struct IPImplHandler_##name : Interface {
#define MY_BEGIN_INTERFACE_(name, parent) \
    struct IPImplHandler_##name : IPImplHandler_##parent \
    { \
        virtual name *getPImpl_##name() = 0;

#define MY_END_INTERFACE }

#define MY_STDMETHOD(name, args) /##/
#define MY_STDMETHOD_(ret_type, name, args) /##/

#define MY_PURE

#include "common/interface.h"
#include "d3d9/decl.h"
#include "d3d9/undef.h"