#include "basiccamera.h"

BasicCamera::BasicCamera(uint32_t width, uint32_t height)
    : tan_fovx(tan(M_PI/2)), tan_fovy(tan((height/width)*(M_PI/2))), _width(width), _height(height), o(0, 0, -5)
{
}


Ray BasicCamera::get_ray(uint32_t u, uint32_t v)
{
   // v = _height - v;
    //float x = ((2.0f * (float)u - _width) / _width) * tan_fovx;
    //float y = ((2.0f * (float)v - _height) / _height) * tan_fovy;
    vec4 d = vec4(u, v, 0) - o;
    return(Ray(o, d.normalize()));
}
