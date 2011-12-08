#ifndef RAYTRACER_H
#define RAYTRACER_H

// Project
#include <cmdflags.h>
#include <modules/basiccamera.h>
#include <modules/image.h>
#include <modules/ray.h>
#include <modules/world.h>


class RayTracer
{
public:
    RayTracer(World &world);



    void render(Image *_image);

private:
    BasicCamera _camera;
    World &_world;

    color &cast(Ray &ray, color &c, Collision &collision);
};

#endif // RAYTRACER_H
