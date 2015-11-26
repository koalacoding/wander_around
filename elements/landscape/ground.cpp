#include "ground.h"

/*-----------------------------
----------CONSTRUCTOR----------
-----------------------------*/

Ground::Ground() : size_x_(20), size_y_(20) {}

Ground::Ground(double size_x, double size_y) {
    size_x_ = size_x;
    size_y_ = size_y;
}

/*----------------------
----------DRAW----------
----------------------*/

void Ground::draw(GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2i(0,0);
    glVertex3i((this->size_x_ / 2) * -1, (this->size_y_ / 2) * -1, -1);
    glTexCoord2i(10,0);
    glVertex3i((this->size_x_ / 2), (this->size_y_ / 2) * -1, -1);
    glTexCoord2i(10,10);
    glVertex3i((this->size_x_ / 2), (this->size_y_ / 2), -1);
    glTexCoord2i(0,10);
    glVertex3i((this->size_x_ / 2) * -1, (this->size_y_ / 2), -1);
    glEnd();
}



