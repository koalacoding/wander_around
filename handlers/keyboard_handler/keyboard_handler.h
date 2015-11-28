#ifndef KEYBOARD_HANDLER_H
#define KEYBOARD_HANDLER_H

#include "../../camera/free_fly_camera/free_fly_camera.h"

class KeyboardHandler
{
public:
    KeyboardHandler();

    void Handle(FreeFlyCamera*);
};

#endif // KEYBOARD_HANDLER_H
