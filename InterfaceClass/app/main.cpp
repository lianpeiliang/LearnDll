#include "logger.h"
#include "business.h"

int main()
{
    ILogger *logger = GetLogger(); // 从 B 获取日志对象。
    DoWork(logger);               // 把接口指针传给 A。
    return 0;
}
