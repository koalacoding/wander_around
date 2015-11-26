#include <iostream>

#include <SDL/SDL.h>

#include "mouse_handler.h"

MouseHandler::MouseHandler()
{

}

void MouseHandler::Handle(FreeFlyCamera *camera) {
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;

            case SDL_MOUSEMOTION:
                camera->OnMouseMotion(event.motion);
                break;
        }
    }
}
