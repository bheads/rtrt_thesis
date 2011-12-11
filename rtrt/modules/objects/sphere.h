#ifndef SPHERE_H
#define SPHERE_H


#include <cmath>

#include <cmdflags.h>

#include <modules/color.h>
#include <modules/ray.h>
#include <modules/objects/object.h>
#include <modules/random.h>

class Sphere : public Object
{
public:
    Sphere();
    Sphere(const vec &pos, float r, const color &c);
    ~Sphere();

    virtual float collision(const Ray &ray, float max);
    virtual bool is_light() { return false; }
    virtual vec &at(const Ray &ray, float dist, vec &v);
    virtual float vec_to(const vec &from, const vec &to, vec &v);
    virtual const vec &center() { return(_pos); }
    virtual const color&get_color() {return(_c);}
    virtual vec &normal(const vec &at, vec &N);
protected:
    vec _pos;
    float _r, _dia;
    color _c;
};

#endif // SPHERE_H
