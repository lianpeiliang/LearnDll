QT = core
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
TARGET = Demo
DESTDIR = $$OUT_PWD/../bin

INCLUDEPATH += $$PWD/../common $$PWD/../writer $$PWD/../reader
LIBS += -L$$DESTDIR -lWriter -lReader
unix: QMAKE_RPATHDIR += $$DESTDIR

SOURCES += main.cpp
