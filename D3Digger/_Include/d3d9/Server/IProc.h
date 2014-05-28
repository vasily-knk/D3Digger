#pragma once

namespace D3D9
{
namespace Server
{
	
template<typename T>
struct IProcExt
{

};


template<typename T>
struct IProc;

#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE_(name, parent)   \
template<>                              \
struct IProc<name>                     \
	: name, IProcExt<name>, IProc<parent> \
{                                       


#define MY_BEGIN_INTERFACE(name)            \
template<>                              \
struct IProc<name>                     \
	: name, IProcExt<name>, Interface  \
{                                       

#define MY_END_INTERFACE };

#define MY_STDMETHOD_(ret_type, name, args) virtual void name(BytesPtr srcBytes, BytesPtr dstBytes) = 0;
#define MY_STDMETHOD(name, args) MY_STDMETHOD_(HRESULT, name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"

} // namespace Server

} // namespace D3D9