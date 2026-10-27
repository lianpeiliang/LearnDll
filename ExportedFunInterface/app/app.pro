QT = core
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
TARGET = Demo

DESTDIR = $$OUT_PWD/../bin

INCLUDEPATH += $$PWD/../business
LIBS += -L$$DESTDIR -lBusiness
unix: QMAKE_RPATHDIR += $$DESTDIR

SOURCES += main.cpp
