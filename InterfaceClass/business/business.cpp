#include "business.h"

void DoWork(ILogger *logger)
{
    if (logger)
        logger->Log("Hello! Business A is using ILogger.");
}
