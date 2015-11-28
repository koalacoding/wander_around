#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H


#include <SDL/SDL.h>

#include "../../camera/camera/camera.h"


class MouseHandler
{
public:
    MouseHandler();

    void Handle(Camera*);
};

#endif // MOUSEHANDLER_H
