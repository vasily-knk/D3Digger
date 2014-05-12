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
				IProxy<IUnknown> *ptr = getByIdImpl(id, createProxy<T>);
				assert(ptr);
				IProxy<T> *converted = dynamic_cast<IProxy<T> *>(ptr);
				assert(converted);
				return converted;
			}
		
		private:
			typedef function<IProxy<IUnknown> *()> Creator;
			virtual IProxy<IUnknown> *getByIdImpl(ProxyId id, Creator creator) = 0;
		};

		typedef shared_ptr<IProxyMap> IProxyMapPtr;
	} // namespace Client

} // namespace D3D9