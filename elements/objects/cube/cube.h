#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <GL/glu.h>

class Cube
{
public:
    /*-----------------------------
    ----------CONSTRUCTOR----------
    -----------------------------*/

    Cube();
    Cube(double angle, double position_x);

    /*--------------------------------
    ----------SET POSITION X----------
    --------------------------------*/

    void set_position_x(double position_x);


    /*--------------------------------------
    ----------------------------------------
    -----------------ANGLE------------------
    ----------------------------------------
    --------------------------------------*/


        /*---------------------------
        ----------GET ANGLE----------
        ---------------------------*/

        double get_angle();

        /*---------------------------
        ----------SET ANGLE----------
        ---------------------------*/

        void set_angle(double angle);


    /*----------------------
    ----------DRAW----------
    ----------------------*/

    void draw(GLuint texture);

private:
    double angle_;
    double position_x_;
};

#endif // CUBE_H
