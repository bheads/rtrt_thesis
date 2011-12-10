#ifndef BASICCAMERA_H
#define BASICCAMERA_H

#include <cmath>

#include <boost/cstdint.hpp>

#include <glog/logging.h>

#include <modules/vec4.h>

class BasicCamera
{
public:
    BasicCamera(uint32_t, uint32_t);

    Ray &get_ray(Ray &ray, float u, float v);
private:
    float _width, _height;
    vec _C, _p, _u, _v;
    float _f, _a, _Sx, _Sy;
    float _aspect, _aspect_2, _width_2, _height_2;
};

#endif // BASICCAMERA_H
