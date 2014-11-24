#pragma once

#include "IProxyMap.h"
#include "d3d9/Client/IExecutor.h"

namespace D3D9
{
	namespace Client
	{

		struct IGlobal
			: Interface
		{
			virtual IProxyMap &proxyMap() = 0;
			virtual IExecutor &executor() = 0;
		};

		IGlobal &getGlobal();
		IGlobal &createGlobal();
		void deleteGlobal();


	} // namespace Client

} // namespace D3D9	