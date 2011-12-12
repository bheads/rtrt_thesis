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
    color pixel;
    vec N, L, R;
    float dist, dret;
    bool hit;
    vec _at;
    ObjectPtr obj_hit;


#pragma omp parallel for private(ray, light_ray, pixel, N, L, R, dist, dret, hit, _at, obj_hit) shared(_image)
    for(int32_t y = 0; y < _image->height(); ++y)
    {
        for(int32_t x = 0; x < _image->width(); ++x)
        {        
            // get our ray
            _camera.get_ray(ray, x, y);
            PerformanceMonitor::instance().RPS.count();
            hit = false;
            dist = 1000000;

            BOOST_FOREACH(const ObjectPtr &obj, _world.objects())
            {
                if((dret = obj->collision(ray, dist)) > 0.0f)
                {
                    obj_hit = obj;
                    dist = dret;
                    hit = true;
                }
            }


            BOOST_FOREACH(const ObjectPtr &obj, _world.lights())
            {
                if((dret = obj->collision(ray, dist)) > 0.0f)
                {
                    obj_hit = obj;
                    dist = dret;
                    hit = true;
                }
            }

            if(hit)
            {
                if(obj_hit->is_light())
                {
                    _image->set(x, y, obj_hit->get_color());
                } else {
                    pixel = 0.01f; // add global light value
                    at(ray, dist, _at);

                    BOOST_FOREACH(const ObjectPtr &light, _world.lights())
                    {
                        dist = obj_hit->vec_to(_at, light->center(), L);
                        obj_hit->normal(_at, N);
                        L.normalize();
                        light_ray._o = _at;
                        light_ray._d = L;

                        BOOST_FOREACH(const ObjectPtr &obj, _world.objects())
                        {
                            if((dret = obj->collision(light_ray, dist)) > 0.0f)
                            {
                                dist = -1.0f;
                                break;
                            }
                        }

                        if(dist > 0.0f)
                        {
                            // diffuse lighting
                            float n_dot_l = dot(N, L);
                            if(n_dot_l > 0.0f)
                            {
                                pixel += obj_hit->diffuse() * n_dot_l * obj_hit->get_color() * light->get_color();
                            }

                            // specular highlights
                            //R = L - (2.0f * N * dot(L, N));
                            float spec_dot = dot(ray._d, L - (2.0f * N * dot(L, N)));
                            if(spec_dot > 0.0f)
                            {
                                pixel += obj_hit->specular() * powf(spec_dot, 20.0f) * light->get_color();
                            }

                        }  // not in shadow

                        // reflections

                        // refractions



                    } // foreach light

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
