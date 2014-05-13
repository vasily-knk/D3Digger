#include "stdafx.h"
#include "IExecutor.h"

namespace D3D9
{
	namespace Client
	{

		struct ExecutorImpl
			: IExecutor
		{
			BytesPtr runSync(MethodId const& id, BytesPtr args) override
			{
				throw std::logic_error("The method or operation is not implemented.");
			}

			void runAsync(MethodId const &id, BytesPtr args) override
			{
				throw std::logic_error("The method or operation is not implemented.");
			}
		};
			
	
		IExecutorPtr createExecutor()
		{
			return make_shared<ExecutorImpl>();
		}
	
	} // namespace Client

} // namespac