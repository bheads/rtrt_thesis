#include "light.h"

Light::Light()
    : Sphere()
{
    _r = 0.01;
    _dia = _r * _r;
    _c.fill(1);
}
