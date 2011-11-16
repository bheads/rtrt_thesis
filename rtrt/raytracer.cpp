#include "raytracer.h"

RayTracer::RayTracer(uint32_t width, uint32_t height)
    : camera(width, height)
{
}


void RayTracer::render(Image *img, World &world)
{
    #pragma omp parallel for
    for(ssize_t y = 0; y < img->height(); ++y)
    {
        for(ssize_t x = 0; x < img->width(); ++x)
        {
            img->set(x, y, cast(camera.get_ray(x, y), color(), 0, world));
        }
    }
}


color RayTracer::cast(Ray ray, color col, uint32_t depth, World &world)
{
    if(++depth > MAX_DEPTH) return(col);
    //Collision hit = world.cast(ray);
    return(col);
}
