#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include "../camera/free_fly_camera/free_fly_camera.h"

class MouseHandler
{
public:
    MouseHandler();

    void Handle(FreeFlyCamera*);
};

#endif // MOUSEHANDLER_H
