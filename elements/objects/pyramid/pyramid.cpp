#include "pyramid.h"

/*-----------------------------
----------CONSTRUCTOR----------
-----------------------------*/

Pyramid::Pyramid() : angle_(0) {

}

Pyramid::Pyramid(double angle) {
    angle_ = angle;
}


/*--------------------------------------
----------------------------------------
-----------------ANGLE------------------
----------------------------------------
--------------------------------------*/


    /*---------------------------
    ----------GET ANGLE----------
    ---------------------------*/

    double Pyramid::get_angle() {
        return this->angle_;
    }

    /*---------------------------
    ----------SET ANGLE----------
    ---------------------------*/

    void Pyramid::set_angle(double angle) {
        this->angle_ = angle;
    }


/*----------------------
----------DRAW----------
----------------------*/

void Pyramid::draw(GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);
    glPushMatrix();
    glTranslated(-1, -1, 0);
    glRotated(this->angle_, 0, 0, 1);

    // Je feinte en dessinant la même face 4 fois avec une rotation.
    for (int i = 0; i < 4; i++) {
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


