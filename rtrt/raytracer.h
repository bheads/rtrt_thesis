#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <cmath>

#include <omp.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>
#include <modules/image.h>
#include <modules/basiccamera.h>
#include <world.h>

#define MAX_DEPTH 4

class RayTracer
{
public:
    RayTracer(uint32_t width, uint32_t height);

    void render(Image *, World &);
    color cast(Ray, color, uint32_t, World &);

private:
    BasicCamera camera;


};

#endif // RAYTRACER_H
