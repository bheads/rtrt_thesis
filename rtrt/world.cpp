#include "world.h"

World::World()
    : spheres()
{
}




void World::add_sphere(float x, float y, float z, float r, color c)
{
    spheres.push_back(Sphere(x, y, z, r, c));
}

void World::add_sphere(vec4 pos, float r, color c)
{
    spheres.push_back(Sphere(pos, r, c));
}



Collision World::cast(Ray &ray)
{
    float mindist = 1000000.0f, dist = 0.0f;
    color col;
    bool hit = false;
    std::vector<Sphere>::iterator it;
    vec4 N, pi;

    for(it = spheres.begin(); it != spheres.end(); ++it)
    {
        if(it->hit(ray, dist))
        {
            if(0.0f < dist && dist < mindist)
            {
                hit = true;
                mindist = dist;
                col = it->get_color();
                pi = at(ray, dist);
                N = it->surface_normal(pi);
            }
        }
    }
    return(Collision(hit, col, mindist, pi, N));
}
