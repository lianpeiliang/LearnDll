#pragma once
#include <QtCore/qglobal.h>
#include "shareddata.h"

#ifdef WRITER_LIBRARY
#  define WRITER_API Q_DECL_EXPORT
#else
#  define WRITER_API Q_DECL_IMPORT
#endif

WRITER_API void AddOne(SharedData *data);
