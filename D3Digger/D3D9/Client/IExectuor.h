#pragma once

#include "IProxy.h"

namespace D3D9
{
	namespace Client
	{

		struct IExecutor
			: Interface
		{
			BytesPtr runSync(ProxyId id, BytesPtr args) = 0;
			void runAsync(ProxyId id, BytesPtr args) = 0;
		};

	} // namespace Client

} // namespace D3D9
