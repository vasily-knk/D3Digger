// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "../Client/IGlobal.h"
#include "d3d9/Methods.h"

IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
	using namespace D3D9;
	using namespace D3D9::Client;

	IGlobal &global = createGlobal();

    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(SDKVersion);

    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::BASE, Methods_BASE::Direct3DCreate9), inBytes);
	bytes::read_proc rp(outBytes);

	ProxyId id = rp.operator()<ProxyId>(); 
	auto ptr = getGlobal().proxyMap().getById<IDirect3D9>(id);

	return ptr;
}

int WINAPI D3DPERF_BeginEvent( D3DCOLOR col, LPCWSTR wszName )
{
    return -1;
}
int WINAPI D3DPERF_EndEvent( void )
{
    return -1;
}
void WINAPI D3DPERF_SetMarker( D3DCOLOR col, LPCWSTR wszName )
{
}
void WINAPI D3DPERF_SetRegion( D3DCOLOR col, LPCWSTR wszName )
{
}
BOOL WINAPI D3DPERF_QueryRepeatFrame( void )
{
    return false;
}

void WINAPI D3DPERF_SetOptions( DWORD dwOptions )
{
}
DWORD WINAPI D3DPERF_GetStatus( void )
{
    return 0;
}