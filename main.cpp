#include <iostream>

#include "sdl_gl_utils/sdl_gl_utils.h"
#include "camera/camera/camera.h"
#include "elements/landscape/ground.h"
#include "elements/objects/cube/cube.h"
#include "elements/objects/pyramid/pyramid.h"
#include "handlers/keyboard_handler/keyboard_handler.h"
#include "handlers/mouse_handler/mouse_handler.h"


#define FPS 60
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PYRAMID_ROTATION_SPEED 0.1
#define CUBE_ROTATION_SPEED 0.05

void LoadTextures(GLuint* texture1, GLuint* texture2, GLuint* texture3);

void DrawGL(Camera* free_fly_camera, GLuint texture1, GLuint texture2, GLuint texture4,
            Cube *cube, Pyramid *pyramid, Ground *ground);

int main(int argc, char *argv[])
{
    SDL_Surface* window = NULL;

    GLuint texture1;
    GLuint texture2;
    GLuint texture4;

    const Uint32 time_per_frame = 1000 / FPS;

    Uint8* keystate = SDL_GetKeyState(NULL);

    Uint32 last_time, current_time, elapsed_time; // For time animation
    Uint32 stop_time; // For frame limit

    Camera* free_fly_camera = new Camera(Vector3D(0,0,1));

    Ground *ground = new Ground(1000, 1000);
    Cube *cube = new Cube();
    Pyramid *pyramid = new Pyramid();

    putenv("SDL_VIDEO_CENTERED=1");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Wander Around", NULL);

    // Anti-aliasing
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 6);

    window = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_OPENGL);

    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(SDL_DISABLE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // If zNear (the third argument) is too close from 0 (like 0.001), huge polygon bleeding can be seen.
    gluPerspective(70, (double) WINDOW_WIDTH / WINDOW_HEIGHT, 0.1, 10000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    texture1 = loadTexture("images/stainedglass05.jpg");
    texture2 = loadTexture("images/tiles_ctf05r.jpg");
    texture4 = loadTexture("images/grass.jpg");

    last_time = SDL_GetTicks();

    while(true) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    delete ground;
                    delete free_fly_camera;
                    delete cube;
                    delete pyramid;
                    glDeleteTextures(1, &texture1);
                    glDeleteTextures(1, &texture2);
                    glDeleteTextures(1, &texture4);
                    return 0;

                case SDL_MOUSEMOTION:
                    free_fly_camera->OnMouseMotion(event.motion);
                    break;
             }
        }

        if (keystate[SDLK_ESCAPE]) {
            return(0);
        }

        if (keystate[SDLK_UP]) {
            free_fly_camera->GoForward(elapsed_time);
        }

        if (keystate[SDLK_DOWN]) {
            free_fly_camera->GoBackward(elapsed_time);
        }

        if (keystate[SDLK_RIGHT]) {
            free_fly_camera->GoRight(elapsed_time);
        }

        if (keystate[SDLK_LEFT]) {
            free_fly_camera->GoLeft(elapsed_time);
        }

        current_time = SDL_GetTicks();
        elapsed_time = current_time - last_time;
        last_time = current_time;

        free_fly_camera->animate(elapsed_time);

        pyramid->set_angle(pyramid->get_angle() + (PYRAMID_ROTATION_SPEED * elapsed_time));
        cube->set_angle(cube->get_angle() + (CUBE_ROTATION_SPEED * elapsed_time));
        cube->set_position_x(2*cos((cube->get_angle()*M_PI)/180));

        DrawGL(free_fly_camera, texture1, texture2, texture4, cube, pyramid, ground);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame) {
           SDL_Delay(time_per_frame - (stop_time - last_time));
        }
    }

    return 0;
}

/*void LoadTextures(GLuint* texture1, GLuint* texture2, GLuint* texture3) {
    *texture1 = loadTexture("../images/stainedglass05.jpg");
    *texture2 = loadTexture("../images/tiles_ctf05r.jpg");
    *texture3 = loadTexture("../images/grass.jpg");
}*/

void DrawGL(Camera* free_fly_camera, GLuint texture1, GLuint texture2, GLuint texture4,
            Cube* cube, Pyramid* pyramid, Ground* ground) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    free_fly_camera->look();

    ground->draw(texture4);
    cube->draw(texture1);
    pyramid->draw(texture2);

    glFlush();
    SDL_GL_SwapBuffers();
}
