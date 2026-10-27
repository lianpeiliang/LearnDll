#pragma once

// 两个动态库共同认识的接口，只有声明，没有日志实现。
class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Log(const char *message) = 0;
};
