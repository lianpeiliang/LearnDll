QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Business
DEFINES += BUSINESS_LIBRARY

DESTDIR = $$OUT_PWD/../bin

INCLUDEPATH += $$PWD/../logger
LIBS += -L$$DESTDIR -lLogger
unix: QMAKE_RPATHDIR += $$DESTDIR

HEADERS += business.h
SOURCES += business.cpp
