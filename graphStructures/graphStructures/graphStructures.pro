TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    NeighbourMatrix.cpp \
    NeighbourLists.cpp \
    Tests.cpp \
    Timer.cpp \
    Algorythms.cpp \
    Pair.cpp

HEADERS += \
    NeighbourMatrix.h \
    NeighbourLists.h \
    TimeTests.h \
    Tests.h \
    Timer.h \
    Algorythms.h \
    Pair.h
