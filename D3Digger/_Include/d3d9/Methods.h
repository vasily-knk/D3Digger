#pragma once

namespace D3D9
{

	enum class Interfaces
	{
		BASE, 

#include "undef.h"
#define MY_BEGIN_INTERFACE_(name, parent) name,
#define MY_BEGIN_INTERFACE(name) name,
#define MY_END_INTERFACE 

#define MY_STDMETHOD_(ret_type, name, args) 
#define MY_STDMETHOD(name, args) 
#define MY_PURE

#include "decl.h"

#include "undef.h"
		TOTAL
	};


	enum class Methods_BASE
	{
		Direct3DCreate9,
		TOTAL
	};

#define MY_BEGIN_INTERFACE(name) enum class Methods_##name {
#define MY_BEGIN_INTERFACE_(name, parent) MY_BEGIN_INTERFACE(name)
#define MY_END_INTERFACE TOTAL };

#define MY_STDMETHOD(name, args) name,
#define MY_STDMETHOD_(ret_type, name, args) MY_STDMETHOD(name, args)
#define MY_PURE

#include "decl.h"
#include "undef.h"


	typedef pair<Interfaces, uint32_t> MethodId;
	template<typename T>
	MethodId makeMethodId(Interfaces i, T m)
	{
		return MethodId(i, static_cast<uint32_t>(m));
	}


} // namespace D3D9