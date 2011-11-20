#ifndef BASICCAMERA_H
#define BASICCAMERA_H

#include <cmath>

#include <boost/cstdint.hpp>
#include <glog/logging.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>

class BasicCamera
{
public:
    BasicCamera(uint32_t, uint32_t);

    Ray get_ray(float, float);

    void moveX(float dist);
    void moveY(float dist);
    void moveZ(float dist);


private:
    float tan_fovx, tan_fovy;
    float _width, _height;

    vec4 o, look;

    float aspect, aspect_2, width_2, height_2;
};

#endif // BASICCAMERA_H
