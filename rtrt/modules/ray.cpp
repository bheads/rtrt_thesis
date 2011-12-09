#include "ray.h"

Ray::Ray()
    : _o(0, 0, 0),
      _d(0, 0, 0)
{
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
