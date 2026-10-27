#pragma once
#include <QtCore/qglobal.h>

#ifdef DOWNLOAD_LIBRARY
#  define DOWNLOAD_API Q_DECL_EXPORT
#else
#  define DOWNLOAD_API Q_DECL_IMPORT
#endif

// 回调函数类型：接收文件名，没有返回值。
using DownloadCallback = void (*)(const char *fileName);

DOWNLOAD_API void DownloadFile(const char *fileName, DownloadCallback onFinished);
