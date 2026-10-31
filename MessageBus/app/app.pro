QT = core
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
TARGET = MessageBusDemo

DESTDIR = $$OUT_PWD/../bin
INCLUDEPATH += $$PWD/../bus $$PWD/../login $$PWD/../notice
LIBS += -L$$DESTDIR -lLoginModule -lNoticeModule -lMessageBusCore
unix: QMAKE_RPATHDIR += $$DESTDIR

SOURCES += main.cpp
