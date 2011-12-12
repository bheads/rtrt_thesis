#ifndef RAYTRACER_H
#define RAYTRACER_H

// Project
#include <cmdflags.h>
#include <modules/basiccamera.h>
#include <modules/image.h>
#include <modules/vec4.h>
#include <modules/vec_func.h>
#include <modules/world.h>
#include <modules/performancemonitor.h>


class RayTracer
{
public:
    RayTracer(World &world);



    void render(Image *_image);

private:
    BasicCamera _camera;
    World &_world;

    color cast(int32_t x, int32_t y, Ray &ray, int32_t level = 1, int32_t max_level = 2);
};

#endif // RAYTRACER_H
