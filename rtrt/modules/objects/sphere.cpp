#include "sphere.h"

Sphere::Sphere()
    : Object(),
      _pos(),
      _r(0),
      _dia(0),
      _c()
{
    _c[0] = Random::getf();
    _c[1] = Random::getf();
    _c[2] = Random::getf();
    _r = Random::getf(1, 5);
    _dia = _r * _r;

    _pos[0] = Random::getf(-25, 25);
    _pos[1] = Random::getf(-25, 25);
    _pos[2] = Random::getf(-5, -100);

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

float Sphere::collision(const Ray &ray, color &col)
{
    vec m = ray._o - _pos;
    float b = m.dot(ray._d);
    float c = m.dot(m) - _dia;
    if(c > 0.0f && b > 0.0f) return(-1.0f);
    float discr = b*b - c;
    if(discr < 0.0f) return(-1.0f);
    float t = -b * sqrt(discr);
    if(t < 0.0f) t = 0.0f;
    col = _c;
    return(t);
}

vec &Sphere::at(const Ray &ray, float dist, vec &v)
{
    v = ray._o + dist * ray._d;
    return(v);
}


vec &Sphere::vec_to(const vec &from, const vec &to, vec &v)
{
    v = to - from;
    return(v);
}


vec &Sphere::normal(const vec &at, vec &N)
{
    N = (at - _pos) * _r;
    N.normalize();
    return N;
}
