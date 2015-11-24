#include "ground.h"

Ground::Ground() {}

void Ground::draw(GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
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
}



