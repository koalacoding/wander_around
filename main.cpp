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

#include "elements/landscape/ground.h"
#include "elements/objects/cube/cube.h"
#include "elements/objects/pyramid/pyramid.h"

#define FPS 50
#define LARGEUR_FENETRE 640
#define HAUTEUR_FENETRE 480

void DrawGL(Cube *cube, Pyramid *pyramid, Ground *ground);

#define VITESSE_ROTATION_CAMERA 0.01
#define VITESSE_ROTATION_PYRAMIDE 0.1
#define VITESSE_ROTATION_CUBE 0.05
double position_x = 0;
double position_y = 0;
double hauteur = 3;

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;

int main(int argc, char *argv[])
{
    SDL_Surface* ecran = NULL;
    SDL_Event event;
    const Uint32 time_per_frame = 1000/FPS;

    Uint32 last_time,current_time,elapsed_time; //for time animation
    Uint32 start_time,stop_time; //for frame limit

    Ground *ground = new Ground();
    Cube *cube = new Cube();
    Pyramid *pyramid = new Pyramid();

    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);

    SDL_WM_SetCaption("SDL GL Application", NULL);
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective(70,(double)LARGEUR_FENETRE/HAUTEUR_FENETRE,1,1000);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    texture1 = loadTexture("../images/stainedglass05.jpg");
    texture2 = loadTexture("../images/tiles_ctf05r.jpg");
    texture3 = loadTexture("../images/caisse.jpg");
    texture4 = loadTexture("../images/grass.jpg");

    last_time = SDL_GetTicks();
    for (;;)
    {

        start_time = SDL_GetTicks();


        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
            }
        }

        Uint8* keystate = SDL_GetKeyState(NULL);

        if(keystate[SDLK_UP]) position_y += 0.2;
        if(keystate[SDLK_DOWN]) position_y-=0.2;
        if(keystate[SDLK_RIGHT]) position_x += 0.2;
        if(keystate[SDLK_LEFT]) position_x -= 0.2;

        current_time = SDL_GetTicks();
        elapsed_time = current_time - last_time;
        last_time = current_time;

        pyramid->set_angle(pyramid->get_angle() + (VITESSE_ROTATION_PYRAMIDE * elapsed_time));

        cube->set_angle(cube->get_angle() + (VITESSE_ROTATION_CUBE * elapsed_time));
        cube->set_position_x(2*cos((cube->get_angle()*M_PI)/180));

        DrawGL(cube, pyramid, ground);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
           SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

    return 0;
}

void DrawGL(Cube *cube, Pyramid *pyramid, Ground *ground)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    gluLookAt(position_x,position_y,1,position_x,position_y + 6,0,0,0,1);
    glRotated(0,1,1,1);

    ground->draw(texture4);
    cube->draw(texture1);
    pyramid->draw(texture2);

    glFlush();
    SDL_GL_SwapBuffers();
}
