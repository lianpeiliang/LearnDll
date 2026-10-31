#include "shareddata.h"
#include "writer.h"
#include "reader.h"

int main()
{
    SharedData data;       // 主程序创建数据，count 初始为 0。

    PrintCount(&data);     // 库 B 读取：0。
    AddOne(&data);         // 库 A 修改：变成 1。
    PrintCount(&data);     // 库 B 再读取：1。

    return 0;
}
