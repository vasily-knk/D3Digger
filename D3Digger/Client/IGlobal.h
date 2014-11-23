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
			virtual ostream &log() = 0;
			virtual IProxyMap &proxyMap() = 0;
			virtual IExecutor &executor() = 0;
		};

		IGlobal &getGlobal();
		IGlobal &createGlobal();
		void deleteGlobal();

#define LOG(str) getGlobal().log() << str << std::endl << std::flush;


	} // namespace Client

} // namespace D3D9	