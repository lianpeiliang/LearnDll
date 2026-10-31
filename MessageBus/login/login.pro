QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = LoginModule
DEFINES += LOGIN_LIBRARY

DESTDIR = $$OUT_PWD/../bin
INCLUDEPATH += $$PWD/../bus
LIBS += -L$$DESTDIR -lMessageBusCore
unix: QMAKE_RPATHDIR += $$DESTDIR

HEADERS += login.h
SOURCES += login.cpp
