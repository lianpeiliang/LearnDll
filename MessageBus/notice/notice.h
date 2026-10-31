#pragma once
#include <QtCore/qglobal.h>

class MessageBus;

#ifdef NOTICE_LIBRARY
#  define NOTICE_API Q_DECL_EXPORT
#else
#  define NOTICE_API Q_DECL_IMPORT
#endif

NOTICE_API void SubscribeLogin(MessageBus *bus);
