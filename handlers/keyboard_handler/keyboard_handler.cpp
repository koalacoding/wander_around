#include <SDL/SDL.h>
#include <iostream>
#include <cmath>

#include "keyboard_handler.h"

KeyboardHandler::KeyboardHandler() {}

void KeyboardHandler::Handle(FreeFlyCamera* camera) {
    /*Uint8* keystate = SDL_GetKeyState(NULL);

    if(keystate[SDLK_UP]) {
        double x_factor = camera->GetLookAtX() - camera->GetPositionX();
        double y_factor = camera->GetLookAtY() - camera->GetPositionY();

        std::cout << x_factor << "-" << y_factor << std::endl;
        camera->SetPositionX(camera->GetLookAtX() + (0.1 * x_factor));
        camera->SetPositionY(camera->GetLookAtY() + (0.1 * y_factor));

        camera->SetLookAtX(camera->GetLookAtX() + (0.1 * x_factor));
        camera->SetLookAtY(camera->GetLookAtY() + (0.1 * x_factor));
    }

    if(keystate[SDLK_DOWN]) {
        camera->SetPositionX(camera->GetLookAtX() - 0.2);
        camera->SetPositionY(camera->GetLookAtY() - 0.2);
    }

    if(keystate[SDLK_RIGHT]) {
        camera->SetPositionX(camera->GetPositionX() + 0.2);
        camera->SetLookAtX(camera->GetLookAtX() + 0.2);
    }

    if(keystate[SDLK_LEFT]) {
        camera->SetPositionX(camera->GetPositionX() - 0.2);
        camera->SetLookAtX(camera->GetLookAtX() - 0.2);
    }*/
}
