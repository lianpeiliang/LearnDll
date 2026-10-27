#include "business.h"
#include "logger.h"

void DoWork()
{
    // Library A directly calls the function exported by library B.
    Log("Hello! Business A is calling Logger B.");
}
