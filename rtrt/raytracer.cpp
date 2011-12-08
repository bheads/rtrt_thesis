#include "raytracer.h"

#include <omp.h>

RayTracer::RayTracer()
    : _camera(FLAGS_width, FLAGS_height)
{
}



void RayTracer::render(Image *_image)
{
    Ray ray;        // current ray
    color light;
    light.zeros();  // base light

#pragma omp parallel for private(light, ray) shared(_image)
    for(int32_t y = 0; y < _image->height(); ++y)
    {
        for(int32_t x = 0; x < _image->width(); ++x)
        {
            _image->set(x, y, cast(_camera.get_ray(ray, x, y), light));
        }
    }
}


color &RayTracer::cast(Ray &ray, color &c)
{
    static vec pos("0 0 -100");
    c.zeros();

    vec p = ray._o - pos;
    float b = -dot(p, ray._d);
    float det = b*b - dot(p, p) + 1;
    if(det < 0.0f) return(c);
    det = sqrt(det);
    if(b + det < 0) return(c);

    c += 1;
    return(c);
}
