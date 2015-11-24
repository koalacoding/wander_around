TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
           sdlglutils.cpp
HEADERS += sdlglutils.h
LIBS += -L/usr/local/lib -lSDL -lSDL_image -ldl -lpthread -lGL -lGLU
INCLUDES += /usr/local/include
