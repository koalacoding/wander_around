#ifndef SDLGLUTILS_H
#define SDLGLUTILS_H


#include <typeinfo>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>


#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

GLuint loadTexture(const char * filename,bool useMipMap = true);
int takeScreenshot(const char * filename);
void drawAxis(double scale = 1);
int initFullScreen(unsigned int * width = NULL,unsigned int * height = NULL);
int XPMFromImage(const char * imagefile, const char * XPMfile);
SDL_Cursor * cursorFromXPM(const char * xpm[]);

#endif //SDLGLUTILS_H
