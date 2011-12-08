#include "basiccamera.h"

BasicCamera::BasicCamera(uint32_t width, uint32_t height)
    :_width(width),
      _height(height),
      _C(),
      _p(),
      _u(),
      _v(),
      _f(1.0f),
      _a(_f),
      _Sx(1.0f),
      _Sy(1.0f),
      _aspect((float)_width/_height),
      _aspect_2(_aspect/2),
      _width_2(_width/2),
      _height_2(_height/2)
{
    _C.zeros(); // start at 0,0,0
    _p.zeros(); // look down +z
    _p[2] = 1.0f;
    _u.zeros(); // left direction
    _u[0] = -1.0f;
    _v.zeros(); // up
    _v[1] = 1.0f;
}


Ray &BasicCamera::get_ray(Ray &ray, float u, float v)
{
    u = ((u - _width_2) / _width_2) * _aspect_2;
    v = ((v - _height_2) / _height_2) * 1.0f;

    ray._o = _C;
    ray._d[0] = u;
    ray._d[1] = v;
    ray._d[2] = -2.0f;

    return(ray);
}


