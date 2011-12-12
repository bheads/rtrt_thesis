#include "light.h"

Light::Light()
    : Sphere()
{
    _r = 0.00001;
    _r2 = _r * _r;
    _c = 1;
}



Light::Light(const vec &pos, float r, const color &c)
    : Sphere(pos, r, c)
{}
