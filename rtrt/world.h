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
    Collision(bool _hit = false, color _c = color(0,0,0), float _d = 0.0f, vec4 pi = vec4(), vec4 N = vec4())
        : col(_c), hit(_hit), dist(_d), at(pi, N)
    {
    }

    color col;
    bool hit;
    float dist;
    Ray at;

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
