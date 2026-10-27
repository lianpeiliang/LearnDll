QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Logger
DEFINES += LOGGER_LIBRARY

# Put all DLLs and the executable in the same directory.
DESTDIR = $$OUT_PWD/../bin

HEADERS += logger.h
SOURCES += logger.cpp
