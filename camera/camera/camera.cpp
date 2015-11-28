#include "camera.h"

Camera::Camera(const Vector3D & position)
{
    _position = position;
    _phi = 0;
    _theta = 0;
    VectorsFromAngles();

    _speed = 0.01;
    _sensivity = 0.2;
    _verticalMotionActive = false;
    _keyconf["forward"] = SDLK_z;
    _keyconf["backward"] = SDLK_s;
    _keyconf["strafe_left"] = SDLK_q;
    _keyconf["strafe_right"] = SDLK_d;
    _keyconf["boost"] = SDLK_LSHIFT;
    _keystates[_keyconf["forward"]] = false;
    _keystates[_keyconf["backward"]] = false;
    _keystates[_keyconf["strafe_left"]] = false;
    _keystates[_keyconf["strafe_right"]] = false;
    _keystates[_keyconf["boost"]] = false;

    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(SDL_DISABLE);
}

void Camera::OnMouseMotion(const SDL_MouseMotionEvent & event)
{
    _theta -= event.xrel*_sensivity;
    _phi -= event.yrel*_sensivity;
    VectorsFromAngles();
}

void Camera::GoForward(Uint32 timestep) {
    static const Vector3D up(0, 0, 1);
    Vector3D temp;
    temp = up.crossProduct(_left);

    _position -= temp * (_speed * timestep);
}

void Camera::GoBackward(Uint32 timestep) {
    static const Vector3D up(0, 0, 1);
    Vector3D temp;
    temp = up.crossProduct(_left);

    _position += temp * (_speed * timestep);
}

void Camera::GoRight(Uint32 timestep) {
    static const Vector3D up(0, 0, 1);
    Vector3D temp;
    temp = up.crossProduct(_forward);

    _position -= temp * (_speed * timestep);
}

void Camera::GoLeft (Uint32 timestep) {
    static const Vector3D up(0, 0, 1);
    Vector3D temp;
    temp = up.crossProduct(_forward);

    _position += temp * (_speed * timestep);
}

void Camera::animate(Uint32 timestep)
{
    _target = _position + _forward;
}

void Camera::setSensivity(double sensivity)
{
    _sensivity = sensivity;
}

void Camera::VectorsFromAngles()
{
    static const Vector3D up(0, 0, 1);
    double r_temp = cos(_phi*M_PI/180);

    if (_phi > 89) _phi = 89;
    else if (_phi < -89) _phi = -89;

    _forward.Z = sin(_phi * M_PI / 180);
    _forward.X = r_temp*cos(_theta * M_PI / 180);
    _forward.Y = r_temp*sin(_theta * M_PI / 180);

    _left = up.crossProduct(_forward);
    _left.normalize();

    _target = _position + _forward;
}

void Camera::look()
{
    gluLookAt(_position.X, _position.Y, _position.Z, _target.X, _target.Y, _target.Z, 0, 0, 1);
}

Camera::~Camera()
{
    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(SDL_DISABLE);
}
