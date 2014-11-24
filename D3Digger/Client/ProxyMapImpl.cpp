#include "stdafx.h"
#include "IProxyMap.h"

namespace D3D9
{
	namespace Client
	{
	
		struct ProxyMapImpl
			: IProxyMap
		{
			typedef IProxy<IUnknown> *ProxyPtr;
			
			ProxyPtr getByIdImpl(ProxyId id, Creator creator) override;

		private:
			void onDeleted(ProxyId id);

		private:
			struct Record
			{
				IProxy<IUnknown> *ptr;
				Connection connDeleted;
			};

			unordered_map<ProxyId, Record> map_;
		};




		IProxy<IUnknown> *ProxyMapImpl::getByIdImpl(ProxyId id, Creator creator)
		{
            if (!map_.count(id))
			{
				Record record;
				record.ptr = creator(id);
				Assert(record.ptr);
				record.connDeleted = record.ptr->subscribeDeleted(bind(&ProxyMapImpl::onDeleted, this, id));

				map_.insert(make_pair(id, std::move(record)));
			}
            else
            {
			    map_.at(id).ptr->AddRef();
            }

            return map_.at(id).ptr;
		}

		void ProxyMapImpl::onDeleted(ProxyId id)
		{
			Assert(map_.count(id));
			map_.erase(id);
		}

		IProxyMapPtr createProxyMap()
		{
			return make_shared<ProxyMapImpl>();
		}
	
	} // namespace Client

} // namespace D3D9