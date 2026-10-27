QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Business
DEFINES += BUSINESS_LIBRARY

DESTDIR = $$OUT_PWD/../bin
INCLUDEPATH += $$PWD/../common

HEADERS += business.h ../common/loggerapi.h
SOURCES += business.cpp
