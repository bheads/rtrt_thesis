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
    Collision collision, light_collision;
    color light(0.1, 0.1, 0.1);
    vec N, L;


#pragma omp parallel for private(light, ray, collision, N, L) shared(_image)
    for(int32_t y = 0; y < _image->height(); ++y)
    {
        for(int32_t x = 0; x < _image->width(); ++x)
        {        
            //if(cast(_camera.get_ray(ray, x, y), light, collision))
            if(_world.cast(_camera.get_ray(ray, x, y), collision))
            {
                if(collision._obj->is_light())
                {
                    _image->set(x, y, collision._color);
                } else {
                    //compute shadow vector
                    if(!_world.shadow(ray, collision, light_collision))
                    {
                        collision._obj->vec_to(collision._at, light_collision._obj->center(), L);
                        collision._obj->normal(collision._at, N);
                        L.normalize();
                        light = collision._color * 0.2f;

                         // diffuse lighting
                        {

                            float d = N.dot(L);
                            if(d > 0.0f)
                            {
                                light[0] += 0.3 * d * collision._color[0] * light_collision._color[0];
                                light[1] += 0.3 * d * collision._color[1] * light_collision._color[1] ;
                                light[2] += 0.3 * d * collision._color[2] * light_collision._color[2];
                            }
                        }

                        _image->set(x, y, light);
                    }

                }
            } else
            {
                _image->clear(x, y);
            }
        }
    }
}


bool RayTracer::cast(Ray &ray, color &c, Collision &collision)
{
    if(_world.cast(ray, collision))
    {
        // add global light
        collision._color += c;
    }
    return(collision._hit);
}
