#pragma once
#include <QtCore/qglobal.h>

// Building Logger: export. Using Logger: import.
#ifdef LOGGER_LIBRARY
#  define LOGGER_API Q_DECL_EXPORT
#else
#  define LOGGER_API Q_DECL_IMPORT
#endif

LOGGER_API void Log(const char *message);
