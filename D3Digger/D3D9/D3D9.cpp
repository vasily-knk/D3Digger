// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "../Client/IGlobal.h"
#include "d3d9/Methods.h"

IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
	using namespace D3D9;
	using namespace D3D9::Client;

	IGlobal &global = getGlobal();

    BytesPtr inBytes = bytes::make();
    bytes::put(SDKVersion, inBytes);
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::BASE, Methods_BASE::Direct3DCreate9), inBytes);
	bytes::getter g(outBytes);

	ProxyId id = g.get<ProxyId>(); 
	auto ptr = getGlobal().proxyMap().getById<IDirect3D9>(id);

	return ptr;
}

