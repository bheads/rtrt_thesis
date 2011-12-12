#ifndef OBJECT_H
#define OBJECT_H

#include <boost/shared_ptr.hpp>
#include <boost/tuple/tuple.hpp>

#include <modules/vec4.h>
#include <modules/vec_func.h>


class Object
{
public:
    Object();
    virtual ~Object() {}

    virtual float collision(const Ray &ray, float max) = 0;
    virtual bool is_light() = 0;
    virtual vec &at(const Ray &ray, float dist, vec &v) = 0;
    virtual float vec_to(const vec &from, const vec &to, vec &v) = 0;
    virtual const vec &center() = 0;
    virtual const color&get_color() = 0;
    virtual vec &normal(const vec &at, vec &N) = 0;
    virtual float diffuse() = 0;
    virtual float specular() = 0;
    virtual float reflection() = 0;
};


//                           hit     object                   dist    color  at
//typedef boost::tuples::tuple<bool, boost::shared_ptr<Object>, float, color, vec>

struct Collision
{
    Collision()
        : _hit(false),
          _obj(),
          _dist(-1),
          _color(0, 0, 0),
          _at(0, 0, 0)
    {}

    bool _hit;
    boost::shared_ptr<Object> _obj;
    float _dist;
    color _color;
    vec _at;
};

#endif // OBJECT_H
