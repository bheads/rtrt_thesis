#include "ray.h"

Ray::Ray()
    : _o(),
      _d()
{
    _o.zeros();
    _d.zeros();
}

Ray::Ray(const vec &o, const vec &d)
    : _o(o),
      _d(d)
{

}

Ray::Ray(const Ray &r)
    : _o(r._o),
      _d(r._d)
{

}
