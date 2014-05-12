#include "stdafx.h"
#include "ProxyBase.h"
#include "GlobalImpl.h"

#include <simex/cpp_utils/thread_safe_object.h>

IGlobal &getGlobal()
{
    static GlobalImpl global;
    return global;
}

void logMethod(const char *interfaceName, const char *methodName)
{
    (void)interfaceName;
    (void)methodName;
    //LOG(interfaceName << "." << methodName);

    static thread_ops::thread_safe_obj<set<Thread::id>> ids;
    auto m = ids.monitor();

    auto threadId = this_thread::get_id();
    if (!m->count(threadId))
    {
        LOG("Thread id " << threadId << " in " << interfaceName << "." << methodName);
        m->insert(threadId);
    }
}

void LogQI(REFIID)
{                           
}

