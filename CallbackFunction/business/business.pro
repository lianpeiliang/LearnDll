QT = core
TEMPLATE = lib
CONFIG += shared c++11
TARGET = Business
DEFINES += BUSINESS_LIBRARY
DESTDIR = $$OUT_PWD/../bin

INCLUDEPATH += $$PWD/../download
LIBS += -L$$DESTDIR -lDownload
unix: QMAKE_RPATHDIR += $$DESTDIR

HEADERS += business.h
SOURCES += business.cpp
