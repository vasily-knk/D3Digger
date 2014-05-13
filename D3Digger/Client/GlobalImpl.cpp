#include "stdafx.h"
#include "IGlobal.h"

namespace D3D9
{
	namespace Client
	{
		struct GlobalImpl
			: IGlobal
		{
			GlobalImpl()
				: log_("d3d9.log")
				, proxyMap_(createProxyMap())
				, executor_(createExecutor())
			{

			}

			ostream &log() override
			{
				return log_;
			}

			IProxyMap &proxyMap() override
			{
				return *proxyMap_;
			}

			IExecutor &executor() override
			{
				return *executor_;
			}

		private:
			ofstream log_;
			IProxyMapPtr proxyMap_;
			IExecutorPtr executor_;
		};
	
	
		IGlobal &getGlobal()
		{
			static GlobalImpl global;
			return global;
		}
	
	} // namespace Client

} // namespace D3D9