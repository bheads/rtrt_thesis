#ifndef SPHERE_H
#define SPHERE_H

#include <ctime>
#include <cmath>

#include <boost/random/uniform_real.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

#include <cmdflags.h>

#include <modules/color.h>
#include <modules/ray.h>
#include <modules/objects/object.h>

class Sphere : public Object
{
public:
    Sphere();
    Sphere(const vec &pos, float r, const color &c);
    ~Sphere();

    virtual float collision(const Ray &ray, color &c);

private:
    vec _pos;
    float _r, _dia;
    color _c;
};

#endif // SPHERE_H
