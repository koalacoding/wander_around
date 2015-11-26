#ifndef FREEFLYCAMERA_H
#define FREEFLYCAMERA_H

#include "../vector3d/vector3d.h"
#include <SDL/SDL.h>
#include <map>
#include <string>

class FreeFlyCamera
{
public:
    FreeFlyCamera(const Vector3D & position = Vector3D(0,0,0));

    void OnMouseMotion(const SDL_MouseMotionEvent & event);
    void OnKeyboard(const SDL_KeyboardEvent & event);

    void GoForward(Uint32 timestep);
    void GoBackward(Uint32 timestep);
    void GoRight(Uint32 timestep);
    void GoLeft(Uint32 timestep);
    void animate(Uint32 timestep);
    void setSensivity(double sensivity);

    void setPosition(const Vector3D & position);

    void look();

    ~FreeFlyCamera();
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

#endif //FREEFLYCAMERA_H
