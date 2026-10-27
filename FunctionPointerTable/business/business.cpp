#include "business.h"

void DoWork(const LoggerApi *api)
{
    // A 只认识函数指针表，通过其中的地址调用 B 的函数。
    if (api && api->Log)
        api->Log("Hello! Business A is using a function pointer table.");
}
