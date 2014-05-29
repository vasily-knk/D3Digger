#pragma once

#include "d3d9/Server/IProc.h"


namespace D3D9
{
namespace Server
{

template<typename T>
struct ProcBase;

#include "d3d9/undef.h"

#define MY_BEGIN_INTERFACE(name) \
	template<> \
	struct ProcBase<name> \
	    : IProc<name> \
	{ \
		typedef name IBase; \
		ProcBase(CreateProcArgs const &args); 

#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)

#define MY_END_INTERFACE \
	private: \
        IProcMapPtr procMap_; \
	};

#define MY_STDMETHOD_(ret_type, name, args) void name(BytesPtr srcBytes, BytesPtr dstBytes) override;
#define MY_STDMETHOD(name, args) MY_STDMETHOD_(HRESULT, name, args)

#include "d3d9/decl.h"
#include "d3d9/undef.h"


} // namespace Server

} // namespace D3D9