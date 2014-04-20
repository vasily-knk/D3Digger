#pragma once

#define MY_BEGIN_INTERFACE(name) struct IProxy_##name : name, Interface {
#define MY_BEGIN_INTERFACE_(name, parent) struct IProxy_##name : IProxy_##parent, name {
#define MY_END_INTERFACE }

#define MY_STDMETHOD(name, args) virtual HRESULT STDMETHODCALLTYPE name args 
#define MY_STDMETHOD_(ret_type, name, args) virtual ret_type STDMETHODCALLTYPE name args

#define MY_PURE = 0

#include "common/interface.h"
#include "d3d9/decl.h"
#include "d3d9/undef.h"