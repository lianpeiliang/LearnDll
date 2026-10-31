#pragma once
#include <QtCore/qglobal.h>

class MessageBus;

#ifdef LOGIN_LIBRARY
#  define LOGIN_API Q_DECL_EXPORT
#else
#  define LOGIN_API Q_DECL_IMPORT
#endif

LOGIN_API void Login(MessageBus *bus);
