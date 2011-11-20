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
    Collision hit = world.cast(ray);
    if(hit.hit)
    {
        vec4 light_at(0, 50, 0);
        vec4 L = light_at - hit.at.o;
        L.normalize();

        float angle = dot(hit.at.d, L);
        if(angle > 0.0f)
        {
            col += 0.9 * angle *  hit.col;
        }
        vec4 R = L - 2.0f * hit.at.d * dot(L, hit.at.d);
        angle = dot(ray.d, R);
        if(angle > 0.0f)
        {
            col += powf(angle, 20.0f) * 0.4f * color(1,1,1);
        }
    }

    return(col);
}
