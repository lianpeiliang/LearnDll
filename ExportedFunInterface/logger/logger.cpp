#include "logger.h"
#include <cstdio>

void Log(const char *message)
{
    std::printf("[Logger B] %s\n", message);
}
