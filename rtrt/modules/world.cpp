#include "world.h"

World::World()
    : _objects()
{
}


void World::fill(uint32_t num, uint32_t lights)
{
    _objects.clear();
    _lights.clear();

    for(uint32_t i = 0; i < num; ++i)
    {
        _objects.push_back(boost::shared_ptr<Object>(new Sphere()));
    }

    for(uint32_t i = 0; i < lights; ++i)
    {
        _lights.push_back(boost::shared_ptr<Object>(new Light()));
    }
}

void World::demo0()
{
    _objects.clear();
    _lights.clear();

    _objects.push_back(boost::shared_ptr<Object>(new Sphere(vec(-3, 0, 10), 3, vec(1,0,0))));
    _objects.push_back(boost::shared_ptr<Object>(new Sphere(vec(3, 0, 10), 3, vec(0,1,0))));
    _objects.push_back(boost::shared_ptr<Object>(new Sphere(vec(0, 0, 20), 7, vec(0,0,1))));


    _lights.push_back(boost::shared_ptr<Object>(new Light(vec(0, 36, 3), 0.001, vec(1,0,0))));
    _lights.push_back(boost::shared_ptr<Object>(new Light(vec(-14,-10, 0), 0.001, vec(1,1,1))));
}


bool World::cast(const Ray &ray, Collision &collision)
{
    float min = 1000000.0f, dist = -1;
    color c;
    collision._hit = false;

    BOOST_FOREACH(const boost::shared_ptr<Object> &obj, _objects)
    {
        if(((dist = obj->collision(ray, min)) > -1.0f) && dist < min)
        {
            collision._hit = true;
            collision._obj = obj;
            collision._dist = dist;
            collision._color = c;
            obj->at(ray, dist, collision._at);
            min = dist;
        }
    }

    BOOST_FOREACH(const boost::shared_ptr<Object> &obj, _lights)
    {
        if(((dist = obj->collision(ray, min)) > -1.0f) && dist < min)
        {
            collision._hit = true;
            collision._obj = obj;
            collision._dist = dist;
            collision._color = c;
            obj->at(ray, dist, collision._at);
            min = dist;
        }
    }

    return(collision._hit);
}

bool World::shadow(Ray &ray, const Collision &collision, Collision &light_collision)
{
    ray._o = collision._at;
    light_collision._hit = false;
    float dist = -1, min;
    bool hit = false;
    color c;

    BOOST_FOREACH(const boost::shared_ptr<Object> &light, _lights)
    {
        light->vec_to(collision._at, light->center(), ray._d);
        min = ray._d.length();
        ray._d.normalize();

        BOOST_FOREACH(const boost::shared_ptr<Object> &obj, _objects)
        {
            if(((dist = obj->collision(ray, min)) > -1.0f) && dist < min)
            {
                hit = true;
                break;
            }

        }

        if(!hit)
        {
            light_collision._hit = true;
            light_collision._obj = light;
            light_collision._dist = min;
            light_collision._color = light->get_color();
            light->at(ray, dist, light_collision._at);
            return(false);
        }
    }
    return(true);
}
