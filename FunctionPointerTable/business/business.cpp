#include "business.h"

void DoWork(const LoggerApi *api)
{
    if (!api)
        return;

    // 一次收到整张表，就可以调用三种功能。
    // 下面只是演示三种输出，不是真的发生了错误。
    if (api->Log)
        api->Log("Business A started.");
    if (api->Warning)
        api->Warning("This is a sample warning.");
    if (api->Error)
        api->Error("This is a sample error.");
}
