#pragma once

#include "common/bytes.h"
#include "d3d9/InterfacesList.h"
#include "IProcMap.h"

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


struct CreateProcArgs
{
    IProcMapPtr procMap;
};

template<typename T>
shared_ptr<IProc<T>> createProc(CreateProcArgs const &args);
#define DEFINE_CREATE_PROC(name) template<> shared_ptr<IProc<name>> createProc<name>(CreateProcArgs const &args);
D3D9_LIST_INTERFACES(DEFINE_CREATE_PROC)
#undef DEFINE_CREATE_PROC


#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE_(name, parent)   \
template<>                              \
struct IProc<name>                     \
	: IProcExt<name>, IProc<parent> \
{                                       


#define MY_BEGIN_INTERFACE(name)            \
template<>                              \
struct IProc<name>                     \
	: IProcExt<name>, Interface  \
{                                       

#define MY_END_INTERFACE };

#define MY_STDMETHOD_(ret_type, name, args) virtual void name(BytesPtr srcBytes, BytesPtr dstBytes) = 0;
#define MY_STDMETHOD(name, args) MY_STDMETHOD_(HRESULT, name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"

} // namespace Server

} // namespace D3D9