#include "sphere.h"

Sphere::Sphere()
    : Object(),
      _pos(),
      _r(0),
      _dia(0),
      _c()
{
    _c.x = Random::getf();
    _c.y = Random::getf();
    _c.z = Random::getf();
    _r = Random::getf(1, 5);
    _dia = _r * _r;

    _pos.x = Random::getf(-25, 25);
    _pos.y = Random::getf(-25, 25);
    _pos.z = Random::getf(5, 100);

    // LOG(INFO) << _pos << "  " << _c;
}


Sphere::Sphere(const vec &pos, float r, const color &c)
    : Object(),
      _pos(pos),
      _r(r),
      _dia(r*r),
      _c(c)
{
}

Sphere::~Sphere()
{

}

float Sphere::collision(const Ray &ray, float max)
{
    vec m = ray._o - _pos;
    float b = dot(m, ray._d);
    float c = dot(m, m) - _dia;
    if(c > 0.0f && b > 0.0f) return(-1.0f);
    float discr = b*b - c;
    if(discr < 0.0f) return(-1.0f);
    float t = -b * sqrtf(discr);
    if( t < 0.0f || t > max) t = -1.0f;
    return(t);
}

vec &Sphere::at(const Ray &ray, float dist, vec &v)
{
    v = ray._o + dist * ray._d;
    return(v);
}


float Sphere::vec_to(const vec &from, const vec &to, vec &v)
{
    v = to - from;
    return(v.length());
}


vec &Sphere::normal(const vec &at, vec &N)
{
    N = (_pos - at);
    N.normalize();
    return N;
}
