TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    NeighbourMatrix.cpp \
    NeighbourLists.cpp \
    MyList.cpp

HEADERS += \
    NeighbourMatrix.h \
    NeighbourLists.h \
    MyList.h
