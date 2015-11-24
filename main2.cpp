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
#include "objects/cube/cube.h"

#define FPS 50
#define LARGEUR_FENETRE 640
#define HAUTEUR_FENETRE 480

void DrawGL(Cube *cube);

#define VITESSE_ROTATION_CAMERA 0.01
#define VITESSE_ROTATION_PYRAMIDE 0.1
#define VITESSE_ROTATION_CUBE 0.05
double position_x = 0;
double position_y = 0;
double angle_pyramide = 0;
double angle_cube = 180;
double x_cube = 2;
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

    Cube *cube = new Cube();

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

        //angle_camera += VITESSE_ROTATION_CAMERA*elapsed_time;
        //hauteur = 2+2*cos(2*angle_camera*M_PI/180);

        angle_pyramide +=  VITESSE_ROTATION_PYRAMIDE*elapsed_time;

        angle_cube += VITESSE_ROTATION_CUBE*elapsed_time;
        cube->set_angle(cube->get_angle() + (VITESSE_ROTATION_CUBE * elapsed_time));

        x_cube = 2*cos((angle_cube*M_PI)/180);
        cube->set_position_x(2*cos((cube->get_angle()*M_PI)/180));

        DrawGL(cube);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
           SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

    return 0;
}

void dessinerCaisse()
{
    glBindTexture(GL_TEXTURE_2D, texture1);
    glPushMatrix();
    glTranslated(x_cube,2,0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    //Je feinte en dessinant la m�me face 4 fois avec une rotation
    for (int i = 0; i < 4; i++)
    {
        glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(1,1,1);
        glTexCoord2d(0,0);
        glVertex3d(1,1,-1);
        glTexCoord2d(1,0);
        glVertex3d(-1,1,-1);
        glTexCoord2d(1,1);
        glVertex3d(-1,1,1);
        glEnd();
        glRotated(90,0,0,1);
    }
    //puis le dessus (pas besoin du dessous gr�ce au sol)
    glBegin(GL_QUADS);
    glTexCoord2d(0,0);
    glVertex3d(1,-1,1);
    glTexCoord2d(1,0);
    glVertex3d(1,1,1);
    glTexCoord2d(1,1);
    glVertex3d(-1,1,1);
    glTexCoord2d(0,1);
    glVertex3d(-1,-1,1);

    glEnd();
    glPopMatrix();

}

void dessinerPyramide()
{

    glBindTexture(GL_TEXTURE_2D, texture2);
    glPushMatrix();
    glTranslated(-1,-1,0);
    glRotated(angle_pyramide,0,0,1);
    //Je feinte en dessinant la m�me face 4 fois avec une rotation
    for (int i = 0; i < 4; i++)
    {
        glBegin(GL_TRIANGLES);
        glTexCoord2d(0,0);
        glVertex3d(1,1,-1);
        glTexCoord2d(1,0);
        glVertex3d(-1,1,-1);
        glTexCoord2d(0.5,1);
        glVertex3d(0,0,1);
        glEnd();
        glRotated(90,0,0,1);
    }
    glPopMatrix();
}

void DrawGL(Cube *cube)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    gluLookAt(position_x,position_y,1,position_x,position_y + 6,0,0,0,1);
    glRotated(0,1,1,1);

    //LE SOL
    glBindTexture(GL_TEXTURE_2D, texture4);
    glBegin(GL_QUADS);
    glTexCoord2i(0,0);
    glVertex3i(-10,-10,-1);
    glTexCoord2i(10,0);
    glVertex3i(10,-10,-1);
    glTexCoord2i(10,10);
    glVertex3i(10,10,-1);
    glTexCoord2i(0,10);
    glVertex3i(-10,10,-1);
    glEnd();

    glColor3ub(255,255,255);

    dessinerCaisse();
    cube->draw(texture1);
    dessinerPyramide();

    glFlush();
    SDL_GL_SwapBuffers();
}
