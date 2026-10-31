#pragma once
#include <QtCore/qglobal.h>
#include "shareddata.h"

#ifdef READER_LIBRARY
#  define READER_API Q_DECL_EXPORT
#else
#  define READER_API Q_DECL_IMPORT
#endif

READER_API void PrintCount(const SharedData *data);
