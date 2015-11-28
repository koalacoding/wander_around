#ifndef KEYBOARD_HANDLER_H
#define KEYBOARD_HANDLER_H


#include <iostream>
#include <cmath>
#include <SDL/SDL.h>

#include "../../camera/camera/camera.h"


class KeyboardHandler
{
public:
    KeyboardHandler();

    void Handle(Camera*);
};

#endif // KEYBOARD_HANDLER_H
