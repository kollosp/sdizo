TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    MyVector.cpp \
    MyList.cpp \
    MyHeap.cpp \
    MyRedBlackTree.cpp \
    Timer.cpp \
    Menu.cpp \
    TimeTests.cpp

HEADERS += \
    MyVector.h \
    MyList.h \
    MyHeap.h \
    MyRedBlackTree.h \
    Timer.h \
    Menu.h \
    TimeTests.h
