#pragma once

#include "IProxy.h"
#include "d3d9/Methods.h"

namespace D3D9
{
	namespace Client
	{

		struct IExecutor
			: Interface
		{
			virtual BytesPtr runSync(MethodId const& id, BytesPtr args) = 0;
			virtual void runAsync(MethodId const &id, BytesPtr args) = 0;
		};

	} // namespace Client

} // namespace D3D9
