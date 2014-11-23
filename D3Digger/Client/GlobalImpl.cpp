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

        std::unique_ptr<GlobalImpl> g_globalImpl;
	
	
		IGlobal &createGlobal()
        {
            assert(!g_globalImpl);
            g_globalImpl = std::make_unique<GlobalImpl>();
            return *g_globalImpl;
        }

        void deleteGlobal()
        {
            assert(g_globalImpl);
            g_globalImpl.reset();
        }
        
        IGlobal &getGlobal()
		{
            assert(g_globalImpl);
            return *g_globalImpl;
		}
	
	} // namespace Client

} // namespace D3D9