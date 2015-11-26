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

            case SDL_KEYUP:
            camera->OnKeyboard(event.key);
            break;

            case SDL_MOUSEMOTION:
                camera->OnMouseMotion(event.motion);
                break;
                /* If the user moves the mouse to the right
                if (event.motion.xrel > 0 && camera->GetLookAtY() > 0.1) {
                    camera->SetLookAtX(camera->GetLookAtX() + 0.1 - camera->GetPositionX());
                    camera->SetLookAtY(camera->GetLookAtY() - 0.1 - camera->GetPositionY());

                    camera->factor_x_ += 0.1;
                    if (camera->factor_x_ > 1) camera->factor_x_ = 1;

                    std::cout << camera->factor_x_ << std::endl;
                    //std::cout << "(" << camera->GetLookAtX() << "," << camera->GetLookAtY() << ")" << std::endl;
                }

                // If the user moves the mouse to the left
                if (event.motion.xrel < 0 && camera->GetLookAtX() > 0.1) {
                    camera->factor_x_ -= 0.1;
                    if (camera->factor_x_ < 0) camera->factor_x_ = 0;

                    std::cout << camera->factor_x_ << std::endl;
                    camera->SetLookAtX(camera->GetLookAtX() - 0.1 - camera->GetPositionX());
                    camera->SetLookAtY(camera->GetLookAtY() + 0.1 - camera->GetPositionY());
                    //std::cout << "(" << camera->GetLookAtX() << "," << camera->GetLookAtY() << ")" << std::endl;
                }
            /*
                if (event.motion.xrel > 0 && camera_angle_x < 50) camera_angle_x++;
                else if (event.motion.xrel < 0 && camera_angle_x > -50) camera_angle_x--;
                std::cout << "(" << camera_angle_x << "," << event.motion.y << ")" << std::endl;
                break;*/
        }
    }
}
