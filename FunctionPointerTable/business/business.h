#pragma once
#include <QtCore/qglobal.h>
#include "loggerapi.h"

#ifdef BUSINESS_LIBRARY
#  define BUSINESS_API Q_DECL_EXPORT
#else
#  define BUSINESS_API Q_DECL_IMPORT
#endif

BUSINESS_API void DoWork(const LoggerApi *api);
