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
				: proxyMap_(createProxyMap())
				, executor_(createExecutor())
			{

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
            logging::add_default_file_writer();
            logging::add_console_writer();

            Verify(!g_globalImpl);
            g_globalImpl = std::make_unique<GlobalImpl>();
            return *g_globalImpl;
        }

        void deleteGlobal()
        {
            Verify(g_globalImpl);
            g_globalImpl.reset();
        }
        
        IGlobal &getGlobal()
		{
            Verify(g_globalImpl);
            return *g_globalImpl;
		}
	
	} // namespace Client

} // namespace D3D9