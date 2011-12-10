#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <vector>

#include <boost/foreach.hpp>

#include <modules/vec4.h>
#include <modules/vec_func.h>

#include <modules/objects/object.h>
#include <modules/objects/sphere.h>
#include <modules/objects/light.h>

typedef std::vector<boost::shared_ptr<Object> > ObjectList;

class World
{
public:
    World();

    void fill(uint32_t num = 25, uint32_t lights = 2);

    void demo0();

    bool cast(const Ray &ray, Collision &collision);

    bool shadow(Ray &ray, const Collision &collision, Collision &light_collision);

    inline const ObjectList &objects() { return(_objects); }
    inline const ObjectList &lights() { return(_lights); }

private:
    ObjectList _objects;
    ObjectList _lights;
};

#endif // WORLD_H
