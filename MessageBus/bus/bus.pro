QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = MessageBusCore
DEFINES += MESSAGEBUS_LIBRARY

DESTDIR = $$OUT_PWD/../bin

HEADERS += messagebus.h
SOURCES += messagebus.cpp
