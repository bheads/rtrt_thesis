#include "sphere.h"

Sphere::Sphere()
    : Object(),
      _pos(),
      _r(0),
      _dia(0),
      _c()
{
    static boost::mt19937 igen;
    static boost::variate_generator<boost::mt19937, boost::uniform_real<> > gen(igen, boost::uniform_real<>(0, 1));


    _c[0] = gen();
    _c[1] = gen();
    _c[2] = gen();
    _r = 1; //(gen() * 10.0f) + 1.0f;
    _dia = _r + _r;

    _pos[0] = (gen() * 50.0f) - 25.0f;
    _pos[1] = (gen() * 50.0f) - 25.0f;
    _pos[2] = (gen() * -1000.0f) - 25000.0f;
}


Sphere::Sphere(const vec &pos, float r, const color &c)
    : Object(),
      _pos(pos),
      _r(r),
      _dia(r+r),
      _c(c)
{
}

Sphere::~Sphere()
{

}



float Sphere::collision(const Ray &ray, color &c)
{
    vec p = ray._o - _pos;
    float b = -arma::dot(p, ray._d);
    float det = b*b - arma::dot(p, p) + _dia;
    if(det < 0.0f) return(-1);
    det = sqrt(det);
    if(b + det < 0) return(-1);
    c = _c;
    return(b - det);
}
