QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Download
DEFINES += DOWNLOAD_LIBRARY
DESTDIR = $$OUT_PWD/../bin

HEADERS += download.h
SOURCES += download.cpp
