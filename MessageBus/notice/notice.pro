QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = NoticeModule
DEFINES += NOTICE_LIBRARY

DESTDIR = $$OUT_PWD/../bin
INCLUDEPATH += $$PWD/../bus
LIBS += -L$$DESTDIR -lMessageBusCore
unix: QMAKE_RPATHDIR += $$DESTDIR

HEADERS += notice.h
SOURCES += notice.cpp
