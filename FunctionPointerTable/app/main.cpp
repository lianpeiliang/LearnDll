#include "logger.h"
#include "business.h"

int main()
{
    LoggerApi api = GetLoggerApi(); // 从 B 获取填好的函数指针表。
    DoWork(&api);                  // 把表的地址传给 A。
    return 0;
}
