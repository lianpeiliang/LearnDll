#include "logger.h"
#include <cstdio>

// 真正的日志函数，只在 B 库内部定义，不需要导出。
static void PrintLog(const char *message)
{
    std::printf("[INFO] %s\n", message);
}

static void PrintWarning(const char *message)
{
    std::printf("[WARNING] %s\n", message);
}

static void PrintError(const char *message)
{
    std::printf("[ERROR] %s\n", message);
}

LoggerApi GetLoggerApi()
{
    LoggerApi api;
    api.Log = &PrintLog; // 把函数地址填入表中。
    api.Warning = &PrintWarning;
    api.Error = &PrintError;
    return api;
}
