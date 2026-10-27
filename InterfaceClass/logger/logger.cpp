#include "logger.h"
#include <cstdio>

// 具体实现只在这个文件里，Business 不需要知道它。
class ConsoleLogger : public ILogger
{
public:
    void Log(const char *message) override
    {
        std::printf("[Logger B] %s\n", message);
    }
};

ILogger *GetLogger()
{
    static ConsoleLogger logger;
    return &logger;
}
