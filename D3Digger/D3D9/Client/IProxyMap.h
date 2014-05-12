#pragma once

#include "common/interface.h"
#include "IProxy.h"
#include "IProxyFactory.h"

namespace D3D9
{
	namespace Client
	{
		struct IProxyMap
			: Interface
		{
			template<typename T>
			IProxy<T> *getById(ProxyId id)
			{
				return getByIdImpl(id, createProxy<T>);
			}
		
		private:
			typedef function<IProxy<IUnknown> *()> Creator;
			virtual IProxy<IUnknown> *getByIdImpl(ProxyId id, Creator creator) = 0;
		};

		typedef shared_ptr<IProxyMap> IProxyMapPtr;
	} // namespace Client

} // namespace D3D9