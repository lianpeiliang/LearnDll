QT = core
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
TARGET = Demo

DESTDIR = $$OUT_PWD/../bin
INCLUDEPATH += $$PWD/../common $$PWD/../logger $$PWD/../business
LIBS += -L$$DESTDIR -lBusiness -lLogger
unix: QMAKE_RPATHDIR += $$DESTDIR

SOURCES += main.cpp
