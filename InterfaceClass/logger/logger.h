#pragma once
#include <QtCore/qglobal.h>
#include "ilogger.h"

#ifdef LOGGER_LIBRARY
#  define LOGGER_API Q_DECL_EXPORT
#else
#  define LOGGER_API Q_DECL_IMPORT
#endif

// 对象由 Logger 库持有，调用者不用 delete。
LOGGER_API ILogger *GetLogger();
