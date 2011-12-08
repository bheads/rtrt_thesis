#include "world.h"

World::World()
    : _objects()
{
}


void World::fill(uint32_t num)
{
    for(uint32_t i = 0; i < num; ++i)
    {
        _objects.push_back(boost::shared_ptr<Object>(new Sphere()));
    }
}



Collision &World::cast(const Ray &ray, Collision &collision)
{
    boost::tuples::get<0>(collision) = false;
    float min = -1, dist = -1;
    color c;

    BOOST_FOREACH(const boost::shared_ptr<Object> &obj, _objects)
    {
        if(((dist = obj->collision(ray, c)) != -1) && (min == -1 || dist < min))
        {
            boost::tuples::get<0>(collision) = true;
            boost::tuples::get<1>(collision) = obj;
            boost::tuples::get<2>(collision) = dist;
            boost::tuples::get<3>(collision) = c;
        }
    }

    return(collision);
}
