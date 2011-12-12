#include "sphere.h"

Sphere::Sphere()
    : Object(),
      _pos(),
      _r(0),
      _r2(0),
      _c(),
      _diffuse(0),
      _specular(0),
      _reflection(0)
{
    _c.x = Random::getf();
    _c.y = Random::getf();
    _c.z = Random::getf();
    _r = Random::getf(1, 15);
    _r2 = _r * _r;

    _pos.x = Random::getf(-105, 105);
    _pos.y = Random::getf(-105, 105);
    _pos.z = Random::getf(-200, 200);

    _diffuse = Random::getf();
    _specular = Random::getf();
    _reflection = Random::getf();
    // LOG(INFO) << _pos << "  " << _c;
}


Sphere::Sphere(const vec &pos, float r, const color &c)
    : Object(),
      _pos(pos),
      _r(r),
      _r2(r*r),
      _c(c),
      _diffuse(1),
      _specular(0.5),
      _reflection(0)
{
}

Sphere::~Sphere()
{

}

float Sphere::collision(const Ray &ray, float max)
{
    vec m;
    sub(ray._o, _pos, m);
    float b = dot(m, ray._d);
    float c = dot(m, m) - _r2;
    if(c > 0.0f && b > 0.0f) return(-1.0f);
    float disc = b * b - c;
    if(disc < 0.0f) return(-1.0f);
    float t = -b - sqrtf(disc);
    if(t > max) t = -1.0f;
    return(t);

    /*
    vec m;
    sub(ray._o, _pos, m);
    float a = dot(ray._d, ray._d);
    float b = 2 * dot(ray._d, m);
    float c = dot(m, m) - _r2;

    //Find discriminant
    float disc = b * b - 4 * a * c;

    // if discriminant is negative there are no real roots, so return
    // false as ray misses sphere
    if (disc < 0) return(-1);

    // compute q as described above
    float distSqrt = sqrtf(disc);
    float q;
    if (b < 0)
        q = (-b - distSqrt)/2.0;
    else
        q = (-b + distSqrt)/2.0;

    // compute t0 and t1
    float t0 = q / a;
    float t1 = c / q;

    // make sure t0 is smaller than t1
    if (t0 > t1) std::swap(t0, t1);
    if (t1 < 0) return(-1);

    // if t0 is less than zero, the intersection point is at t1
    if (t0 < 0) {
        if(t1 < max) return(t1);
        return(-1.0f);
    }
    else if(t0 < max) return(t0);

    return(-1);
    */
}

vec &Sphere::at(const Ray &ray, float dist, vec &v)
{
    v = ray._o + (dist * ray._d);
    return(v);
}


float Sphere::vec_to(const vec &from, const vec &to, vec &v)
{
    sub(to, from, v);
    //v = to - from;
    return(v.length());
}


vec &Sphere::normal(const vec &at, vec &N)
{
    sub(at, _pos, N).normalize();
    //N = (_pos - at);
    //N.normalize();
    return N;
}
