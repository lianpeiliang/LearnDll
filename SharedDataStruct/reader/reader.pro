QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Reader
DEFINES += READER_LIBRARY
DESTDIR = $$OUT_PWD/../bin

INCLUDEPATH += $$PWD/../common
HEADERS += reader.h ../common/shareddata.h
SOURCES += reader.cpp
