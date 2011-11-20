#include "basiccamera.h"

BasicCamera::BasicCamera(uint32_t width, uint32_t height)
    : tan_fovx(tan(M_PI/2)), tan_fovy(tan((height/width)*(M_PI/2))), _width(width), _height(height), o(), look(0,0,-1),
      aspect((float)width/height), aspect_2(aspect/2), width_2(width/2), height_2(height/2)
{
}


Ray BasicCamera::get_ray(float u, float v)
{

    u = ((u - width_2) / width_2) * aspect_2;
    v = ((v - height_2) / height_2) * 0.5;
    vec4 d(u, v, -1.01);
    return(Ray(o, d.normalize()));
}


void BasicCamera::moveX(float dist)
{
    o.x += dist;
}


void BasicCamera::moveY(float dist)
{
    o.y += dist;
}

void BasicCamera::moveZ(float dist)
{
    o.z += dist;
}

