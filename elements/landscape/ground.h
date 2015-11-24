#ifndef GROUND_H
#define GROUND_H

#include <GL/glu.h>

class Ground
{
public:
    /*-----------------------------
    ----------CONSTRUCTOR----------
    -----------------------------*/

    Ground();

    /*----------------------
    ----------DRAW----------
    ----------------------*/

    void draw(GLuint texture);
};

#endif // GROUND_H
