QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Writer
DEFINES += WRITER_LIBRARY
DESTDIR = $$OUT_PWD/../bin

INCLUDEPATH += $$PWD/../common
HEADERS += writer.h ../common/shareddata.h
SOURCES += writer.cpp
