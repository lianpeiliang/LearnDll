#include "reader.h"
#include <cstdio>

void PrintCount(const SharedData *data)
{
    // 读取主程序传来的同一份数据。
    std::printf("Reader: count = %d\n", data->count);
}
