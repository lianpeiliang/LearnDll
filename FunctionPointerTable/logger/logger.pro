QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Logger
DEFINES += LOGGER_LIBRARY

DESTDIR = $$OUT_PWD/../bin
INCLUDEPATH += $$PWD/../common

HEADERS += logger.h ../common/loggerapi.h
SOURCES += logger.cpp
