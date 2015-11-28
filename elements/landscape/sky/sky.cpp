#include "sky.h"

Sky::Sky() {}

/*----------------------
----------DRAW----------
----------------------*/

void Sky::draw(GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0);
    glVertex3i((size_x_ / 2) * -1, (size_y_ / 2) * -1, -1);

    glTexCoord2i((size_x_ / 2), 0);
    glVertex3i((size_x_ / 2), (size_y_ / 2) * -1, -1);

    glTexCoord2i((size_x_ / 2), (size_y_ / 2));
    glVertex3i((size_x_ / 2), (size_y_ / 2), -1);

    glTexCoord2i(0, (size_y_ / 2));
    glVertex3i((size_x_ / 2) * -1, (size_y_ / 2), -1);
    glEnd();
}
