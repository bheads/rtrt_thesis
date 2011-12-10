#include "raytracer.h"

#include <omp.h>

RayTracer::RayTracer(World &world)
    : _camera(FLAGS_width, FLAGS_height),
      _world(world)
{
}



void RayTracer::render(Image *_image)
{
    Ray ray, light_ray;        // current ray
    Collision collision;
    color pixel(0, 0, 0), tmp;
    vec N, L;
    float dist, dret;


#pragma omp parallel for private(ray, light_ray, collision,pixel, tmp, N, L, dist, dret) shared(_image)
    for(int32_t y = 0; y < _image->height(); ++y)
    {
        for(int32_t x = 0; x < _image->width(); ++x)
        {        
            //if(cast(_camera.get_ray(ray, x, y), light, collision))
            if(_world.cast(_camera.get_ray(ray, x, y), collision))
            {
                if(collision._obj->is_light())
                {
                    // render the light in all its glory
                    _image->set(x, y, collision._color);
                } else {
                    // setup lighting
                    pixel = 0;

                    //compute light effect
                    BOOST_FOREACH(const boost::shared_ptr<Object> &light, _world.lights())
                    {
                        // compute normal at collition point
                        collision._obj->normal(collision._at, N);
                        // compute vector to light
                        L = light->center() - collision._at;
                        // compute length of light vector
                        dist = L.length();
                        // compute distance to light
                        L.normalize();
                        // compute ray from collision point to light source
                        light_ray._o = collision._at;
                        light_ray._d = L;

                        // test for collision with other objects
                        BOOST_FOREACH(const boost::shared_ptr<Object> &obj, _world.objects())
                        {
                            if((dret = obj->collision(light_ray, tmp)) > -1.0f && dret < dist)
                            {
                                dist = -1.0f;
                                break;
                            }
                        }

                        // did we hit an object?
                        if(dist > 0)
                        {
                            float _dot = dot(N, L);
                            if(_dot > 0)
                            {
                                pixel += 0.3 * _dot * collision._color * light->get_color();
                            }
                        }

                    } // light test

                    _image->set(x, y, pixel);
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
