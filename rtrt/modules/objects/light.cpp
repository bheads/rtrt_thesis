#include "light.h"

Light::Light()
    : Sphere()
{
    _r = 0.00001;
    _dia = _r + _r;
    _c.fill(1);
}



Light::Light(const vec &pos, float r, const color &c)
    : Sphere(pos, r, c)
{}
