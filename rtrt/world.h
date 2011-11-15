#ifndef WORLD_H
#define WORLD_H

#include <cmath>

#include <algorithm>
#include <vector>

#include <boost/foreach.hpp>

#include <omp.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>

#include <objects/sphere.h>

struct Collision
{
    Collision(bool _hit = false, color _c = color(0,0,0))
        : col(_c), hit(_hit)
    {
    }

    color col;
    bool hit;
};

class World
{
public:
    World();

    void add_sphere(vec4 pos, float r, color c);
    void add_sphere(float x, float y, float z, float r, color c);

    Collision cast(Ray &ray);

private:
    std::vector<Sphere> spheres;

};

#endif // WORLD_H
