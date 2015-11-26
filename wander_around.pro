TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
           sdl_gl_utils/sdl_gl_utils.cpp\
           elements/objects/cube/cube.cpp \
           elements/objects/pyramid/pyramid.cpp \
           elements/landscape/ground.cpp \
           camera/camera.cpp \
    handlers/keyboard_handler/keyboard_handler.cpp \
    handlers/mouse_handler/mouse_handler.cpp \
    camera/vector3d/vector3d.cpp \
    camera/free_fly_camera/free_fly_camera.cpp

HEADERS += sdl_gl_utils/sdl_gl_utils.h\
           elements/objects/cube/cube.h \
           elements/objects/pyramid/pyramid.h \
           elements/landscape/ground.h \
           camera/camera.h \
    handlers/keyboard_handler/keyboard_handler.h \
    handlers/mouse_handler/mouse_handler.h \
    camera/vector3d/vector3d.h \
    camera/free_fly_camera/free_fly_camera.h

LIBS += -L/usr/local/lib -lSDL -lSDL_image -ldl -lpthread -lGL -lGLU

INCLUDES += /usr/local/include
