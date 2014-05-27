#pragma once

#include "common/interface.h"
#include "d3d9/IProxy.h"
#include "ProxyFactory.h"

namespace D3D9
{
	namespace Client
	{
		struct IProxyMap;
		typedef shared_ptr<IProxyMap> IProxyMapPtr;

		IProxyMapPtr createProxyMap();		
		
		struct IProxyMap
			: Interface
		{
			template<typename T>
			IProxy<T> *getById(ProxyId id)
			{
				IProxy<IUnknown> *ptr = getByIdImpl(id, createProxy<T>);
				assert(ptr);
				IProxy<T> *converted = dynamic_cast<IProxy<T> *>(ptr);
				assert(converted);
				return converted;
			}
		
		protected:
			typedef function<IProxy<IUnknown> *(ProxyId)> Creator;
			virtual IProxy<IUnknown> *getByIdImpl(ProxyId id, Creator creator) = 0;
		};

		typedef shared_ptr<IProxyMap> IProxyMapPtr;
	} // namespace Client

} // namespace D3D9