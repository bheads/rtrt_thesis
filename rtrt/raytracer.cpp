#include "raytracer.h"

#include <omp.h>

RayTracer::RayTracer(World &world)
    : _camera(FLAGS_width, FLAGS_height),
      _world(world)
{
}



void RayTracer::render(Image *_image)
{
    Ray ray;        // current ray
    color light;
    light.zeros();  // base light
    Collision collision;

#pragma omp parallel for private(light, ray, collision) shared(_image)
    for(int32_t y = 0; y < _image->height(); ++y)
    {
        for(int32_t x = 0; x < _image->width(); ++x)
        {
            _image->set(x, y, cast(_camera.get_ray(ray, x, y), light, collision));
        }
    }
}


color &RayTracer::cast(Ray &ray, color &c, Collision &collision)
{
    c.zeros();
    if(_world.cast(ray, collision).get<0>())
    {
        c += collision.get<3>();
    }

    return(c);
}
