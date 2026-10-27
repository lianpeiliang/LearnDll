#pragma once

// 函数指针表：这里为了简单，只放一个函数指针。
struct LoggerApi
{
    void (*Log)(const char *message);
};
