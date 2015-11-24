TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
           sdl_gl_utils/sdl_gl_utils.cpp

HEADERS += sdl_gl_utils/sdl_gl_utils.h

LIBS += -L/usr/local/lib -lSDL -lSDL_image -ldl -lpthread -lGL -lGLU

INCLUDES += /usr/local/include
