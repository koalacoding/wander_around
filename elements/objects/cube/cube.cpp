#include "cube.h"

/*-----------------------------
----------CONSTRUCTOR----------
-----------------------------*/

Cube::Cube() : angle_(180), position_x_(2) {

}

Cube::Cube(double angle, double position_x) {
    angle_ = angle;
    position_x_ = position_x;
}

/*--------------------------------
----------SET POSITION X----------
--------------------------------*/

void Cube::set_position_x(double position_x) {
    this->position_x_ = position_x;
}


/*--------------------------------------
----------------------------------------
-----------------ANGLE------------------
----------------------------------------
--------------------------------------*/


    /*---------------------------
    ----------GET ANGLE----------
    ---------------------------*/

    double Cube::get_angle() {
        return this->angle_;
    }

    /*---------------------------
    ----------SET ANGLE----------
    ---------------------------*/

    void Cube::set_angle(double angle) {
        this->angle_ = angle;
    }


/*----------------------
----------DRAW----------
----------------------*/

void Cube::draw(GLuint texture)
{
    glPushMatrix();
    glTranslated(this->position_x_, 2, 0);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Je feinte en dessinant la même face 4 fois avec une rotation.
    for (int i = 0; i < 4; i++) {
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

    // Puis le dessus (pas besoin du dessous grâce au sol).
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
