#include "stdafx.h"

INT WINAPI Texture_wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT );
INT WINAPI Mesh_wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT );


INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPWSTR pCmdLine, INT nCmdShow)
{
    return Texture_wWinMain(hInst, hPrevInstance, pCmdLine, nCmdShow);
}
