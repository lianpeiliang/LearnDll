#pragma once

// 一张表提供三种功能，传一次就能使用全部功能。
struct LoggerApi
{
    void (*Log)(const char *message);
    void (*Warning)(const char *message);
    void (*Error)(const char *message);
};
