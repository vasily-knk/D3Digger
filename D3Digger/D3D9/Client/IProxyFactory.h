#pragma once

#include "IProxy.h"

namespace D3D9
{
	namespace Client
	{

		template<typename T>
		IProxy<T> *createProxy()
		{
			return nullptr; 
		}

	} // namespace Client

} // namespace D3D9