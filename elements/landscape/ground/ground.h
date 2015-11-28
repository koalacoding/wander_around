#ifndef GROUND_H
#define GROUND_H

#include <GL/glu.h>

class Ground
{
  public:
    Ground();
    Ground(double size_x, double size_y);
    void draw(GLuint texture);

  private:
    double size_x_;
    double size_y_;
};

#endif // GROUND_H
