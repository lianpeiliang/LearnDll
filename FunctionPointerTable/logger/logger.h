#pragma once
#include <QtCore/qglobal.h>
#include "loggerapi.h"

#ifdef LOGGER_LIBRARY
#  define LOGGER_API Q_DECL_EXPORT
#else
#  define LOGGER_API Q_DECL_IMPORT
#endif

LOGGER_API LoggerApi GetLoggerApi();
