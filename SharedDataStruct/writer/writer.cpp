#include "writer.h"

void AddOne(SharedData *data)
{
    // 修改主程序传来的那份数据。
    data->count += 1;
}
