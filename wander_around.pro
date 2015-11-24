TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
           sdl_gl_utils/sdl_gl_utils.cpp\
           elements/objects/cube/cube.cpp \
           elements/objects/pyramid/pyramid.cpp \
    elements/landscape/ground.cpp

HEADERS += sdl_gl_utils/sdl_gl_utils.h\
           elements/objects/cube/cube.h \
           elements/objects/pyramid/pyramid.h \
    elements/landscape/ground.h

LIBS += -L/usr/local/lib -lSDL -lSDL_image -ldl -lpthread -lGL -lGLU

INCLUDES += /usr/local/include
