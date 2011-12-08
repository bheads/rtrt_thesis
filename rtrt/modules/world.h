#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <vector>

#include <boost/foreach.hpp>

#include <modules/color.h>
#include <modules/ray.h>

#include <modules/objects/object.h>
#include <modules/objects/sphere.h>


class World
{
public:
    World();

    void fill(uint32_t num = 25);

    Collision &cast(const Ray &ray, Collision &collision);
private:
    std::vector<boost::shared_ptr<Object> > _objects;
};

#endif // WORLD_H
