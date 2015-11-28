#ifndef SKY_H
#define SKY_H

#include <GL/glu.h>

class Sky
{
  public:
    Sky();
    void draw(GLuint);

  private:
    double size_x_;
    double size_y_;
};

#endif // SKY_H
