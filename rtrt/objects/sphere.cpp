#include "sphere.h"

Sphere::Sphere(float x, float y, float z, float _r, color c)
    : pos(x, y, z), r(_r), dia(r+r), col(c)
{
}

Sphere::Sphere(vec4 _pos, float _r, color c)
    : pos(_pos), r(_r), dia(r+r), col(c)
{
}


bool Sphere::hit(Ray &ray, float &dist)
{
    dist = -1.0f;
    vec4 p = ray.o - pos;
    float b = -dot(p, ray.d);
    float det = b*b - dot(p, p) + dia;
    if(det < 0.0f) return false;
    det = sqrt(det);
    if(b + det < 0) return false;
    dist = b - det;
    return true;
}

const vec4 Sphere::surface_normal(const vec4 &at)
{
    vec4 N = (at - pos) * r;
    return(N.normalize());
}
