#ifndef BASICCAMERA_H
#define BASICCAMERA_H

#include <cmath>

#include <boost/cstdint.hpp>

#include <modules/vec4.h>
#include <modules/vec_func.h>

class BasicCamera
{
public:
    BasicCamera(uint32_t, uint32_t);

    Ray get_ray(uint32_t, uint32_t);

private:
    float tan_fovx, tan_fovy;
    float _width, _height;

    vec4 o;
};

#endif // BASICCAMERA_H
