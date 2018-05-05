TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    state.cpp \
    rest_null_state.cpp \
    rest_two_state.cpp \
    rest_three_state.cpp \
    state_machine.cpp \
    unknown_state.cpp \
    rest_one_state.cpp

HEADERS += \
    state.h \
    rest_null_state.h \
    rest_two_state.h \
    rest_three_state.h \
    state_machine.h \
    unknown_state.h \
    rest_one_state.h
