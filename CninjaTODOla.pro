TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        externRepresentation.cpp \
        main.cpp \
        ninjatodolalist.cpp \
        ninjatodolaobject.cpp \
        tasklist.cpp

HEADERS += \
    externRepresentation.h \
    ninjatodolalist.h \
    ninjatodolaobject.h \
    tasklist.h
