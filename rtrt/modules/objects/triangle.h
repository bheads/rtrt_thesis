#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

#include <cmdflags.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>
#include <modules/objects/object.h>
#include <modules/random.h>

/**
  @TODO: Fix center method if we want to use a triangle as apoint light...
  */
class Triangle : public Object
{
public:
    Triangle();
    Triangle(const vec &a, const vec &b, const vec &c, const color &col);
    ~Triangle();

    virtual float collision(const Ray &ray, float max);
    virtual bool is_light() { return false; }
    virtual vec &at(const Ray &ray, float dist, vec &v);
    virtual float vec_to(const vec &from, const vec &to, vec &v);
    virtual const vec &center() { return(_a); }
    virtual const color&get_color() {return(_color);}
    virtual vec &normal(const vec &at, vec &N);

    virtual inline float diffuse() { return _diffuse; }
    virtual inline float specular() { return _specular; }
    virtual inline float reflection() { return _reflection; }
protected:
    vec _a, _b, _c, _N;
    color _color;
    float _diffuse, _specular, _reflection;
};

#endif // TRIANGLE_H
