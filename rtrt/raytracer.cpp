#include "raytracer.h"

#include <omp.h>

RayTracer::RayTracer(World &world)
    : _camera(FLAGS_width, FLAGS_height),
      _world(world)
{
}



void RayTracer::render(Image *_image)
{
Ray ray;

//private(ray, light_ray, pixel, N, L, dist, dret, hit, _at, obj_hit)
#pragma omp parallel for private(ray) shared(_image)
    for(int32_t y = 0; y < _image->height(); ++y)
    {
        for(int32_t x = 0; x < _image->width(); ++x)
        {
             _camera.get_ray(ray, x, y);
            _image->set(x, y, cast(x, y, ray));
        }
    }
}


color RayTracer::cast(int32_t x, int32_t y, Ray &ray, int32_t level, int32_t max_level)
{
    Ray light_ray;        // current ray
    color pixel;
    vec N, L;
    float dist, dret;
    bool hit;
    vec _at;
    ObjectPtr obj_hit;

    if(level > max_level) return pixel;


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
            return(obj_hit->get_color());
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
                if(obj_hit->reflection() > 0)
                {
                    light_ray._d = (ray._d - (2.0f * N * dot(ray._d, N)));
                    light_ray._d.normalize();
                    light_ray._o = _at + (light_ray._d * 0.00001f);
                    pixel += obj_hit->reflection() * cast(x, y, light_ray, level + 1, max_level) * obj_hit->get_color();
                }


                // refractions

            } // foreach light

            return(pixel);
        }
    }
    return(pixel);
}
