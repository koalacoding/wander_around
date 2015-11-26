#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <fstream>

#include "sdl_gl_utils/sdl_gl_utils.h"

#include "camera/camera.h"
#include "camera/free_fly_camera/free_fly_camera.h"
#include "elements/landscape/ground.h"
#include "elements/objects/cube/cube.h"
#include "elements/objects/pyramid/pyramid.h"
#include "handlers/keyboard_handler/keyboard_handler.h"
#include "handlers/mouse_handler/mouse_handler.h"

#define FPS 50
#define LARGEUR_FENETRE 640
#define HAUTEUR_FENETRE 480

void DrawGL(FreeFlyCamera* free_fly_camera, Cube *cube, Pyramid *pyramid, Ground *ground, int camera_angle_x);

#define VITESSE_ROTATION_CAMERA 0.01
#define VITESSE_ROTATION_PYRAMIDE 0.1
#define VITESSE_ROTATION_CUBE 0.05
double hauteur = 3;

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;

void stop()
{
    //delete free_fly_camera;
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    SDL_Surface* ecran = NULL;
    const Uint32 time_per_frame = 1000/FPS;

    Uint8* keystate = SDL_GetKeyState(NULL);

    Uint32 last_time, current_time, elapsed_time; // For time animation
    Uint32 start_time, stop_time; // For frame limit

    Camera *camera = new Camera();
    FreeFlyCamera* free_fly_camera = new FreeFlyCamera(Vector3D(0,0,2));

    Ground *ground = new Ground(100, 100);
    Cube *cube = new Cube();
    Pyramid *pyramid = new Pyramid();

    KeyboardHandler *keyboard_handler = new KeyboardHandler();
    MouseHandler *mouse_handler = new MouseHandler();

    int camera_angle_x(0);

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetCaption("SDL GL Application", NULL);
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective(70, (double)LARGEUR_FENETRE/HAUTEUR_FENETRE, 0.001, 1000);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    texture1 = loadTexture("../images/stainedglass05.jpg");
    texture2 = loadTexture("../images/tiles_ctf05r.jpg");
    texture3 = loadTexture("../images/caisse.jpg");
    texture4 = loadTexture("../images/grass.jpg");



    last_time = SDL_GetTicks();

    while(true) {
        start_time = SDL_GetTicks();

        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    delete free_fly_camera;
                    exit(0);
                    break;

                /*case SDL_KEYUP:
                free_fly_camera->OnKeyboard(event.key);
                break;*/

                case SDL_MOUSEMOTION:
                    free_fly_camera->OnMouseMotion(event.motion);
                    break;

             }
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

        //mouse_handler->Handle(free_fly_camera);
        //keyboard_handler->Handle(camera);

        current_time = SDL_GetTicks();
        elapsed_time = current_time - last_time;
        last_time = current_time;

        free_fly_camera->animate(elapsed_time, event.key);

        pyramid->set_angle(pyramid->get_angle() + (VITESSE_ROTATION_PYRAMIDE * elapsed_time));

        cube->set_angle(cube->get_angle() + (VITESSE_ROTATION_CUBE * elapsed_time));
        cube->set_position_x(2*cos((cube->get_angle()*M_PI)/180));

        DrawGL(free_fly_camera, cube, pyramid, ground, camera_angle_x);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
           SDL_Delay(time_per_frame - (stop_time - last_time));
        }
    }

    return 0;
}

void DrawGL(FreeFlyCamera* free_fly_camera, Cube *cube, Pyramid *pyramid, Ground *ground, int camera_angle_x)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    free_fly_camera->look();

    ground->draw(texture4);
    cube->draw(texture1);
    pyramid->draw(texture2);

    glFlush();
    SDL_GL_SwapBuffers();
}
