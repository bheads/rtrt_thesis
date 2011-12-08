#ifndef OBJECT_H
#define OBJECT_H

#include <boost/shared_ptr.hpp>
#include <boost/tuple/tuple.hpp>

#include <modules/color.h>
#include <modules/ray.h>


class Object
{
public:
    Object();
    virtual ~Object() {}


    virtual float collision(const Ray &ray, color &c) = 0;
};



//                           hit     object                   dist    color
typedef boost::tuples::tuple<bool, boost::shared_ptr<Object>, float, color> Collision;

#endif // OBJECT_H
