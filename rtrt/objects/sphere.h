#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include <omp.h>

#include <boost/cstdint.hpp>


#include <modules/vec4.h>
#include <modules/vec_func.h>

class Sphere
{
public:
    Sphere(float x, float y, float z, float _r, color c);
    Sphere(vec4 _pos, float _r, color c);

    bool hit(Ray &ray, float &dist);

    const color &get_color() { return(col); }
    const vec4 surface_normal(const vec4 &at);

private:
    vec4 pos;
    float r, dia;
    color col;
};

#endif // SPHERE_H
