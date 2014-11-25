#include "stdafx.h"

#include "ExecutorASIO.h"
#include "ExecutorDummy.h"

namespace D3D9
{
namespace Client
{

IExecutorPtr createExecutor()
{
	return make_shared<ExecutorDummy>();
}


    	
} // namespace Client

} // namespace D3D9