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

//#pragma omp parrallel for shared(dist, mindist, hit, col)
    for(size_t i = 0; i < spheres.size(); ++i)
    {
        if(spheres[i].hit(ray, dist))
        {
            if(0.0f < dist && dist < mindist)
            {
                hit = true;
                mindist = dist;
                col = spheres[i].get_color();
            }
        }
    }
    return(Collision(hit, col));
}
