#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <vector>

#include <boost/foreach.hpp>

#include <modules/color.h>
#include <modules/ray.h>

#include <modules/objects/object.h>
#include <modules/objects/sphere.h>
#include <modules/objects/light.h>


class World
{
public:
    World();

    void fill(uint32_t num = 25, uint32_t lights = 2);

    bool cast(const Ray &ray, Collision &collision);

    bool shadow(Ray &ray, const Collision &collision, Collision &light_collision);
private:
    std::vector<boost::shared_ptr<Object> > _objects;
    std::vector<boost::shared_ptr<Object> > _lights;
};

#endif // WORLD_H
