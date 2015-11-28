#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <map>
#include <string>
#include <GL/glu.h>
#include <SDL/SDL.h>

#include "../vector3d/vector3d.h"


class Camera
{
public:
    Camera(const Vector3D & position = Vector3D(0,0,0));

    void OnMouseMotion(const SDL_MouseMotionEvent & event);

    void GoForward(Uint32 timestep);
    void GoBackward(Uint32 timestep);
    void GoRight(Uint32 timestep);
    void GoLeft(Uint32 timestep);
    void animate(Uint32 timestep);
    void setSensivity(double sensivity);

    void look();

    ~Camera();
protected:
    double _speed;
    double _sensivity;

    //vertical motion stuffs
    Uint32 _timeBeforeStoppingVerticalMotion;
    bool _verticalMotionActive;
    int _verticalMotionDirection;

    typedef std::map<SDLKey,bool> KeyStates;
    KeyStates _keystates;
    typedef std::map<std::string,SDLKey> KeyConf;
    KeyConf _keyconf;

    Vector3D _position;
    Vector3D _target;
    Vector3D _forward;
    Vector3D _left;
    double _theta;
    double _phi;

    void VectorsFromAngles();
};

#endif //CAMERA_H
