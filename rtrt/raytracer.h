#ifndef RAYTRACER_H
#define RAYTRACER_H

// Project
#include <cmdflags.h>
#include <modules/basiccamera.h>
#include <modules/image.h>
#include <modules/ray.h>



class RayTracer
{
public:
    RayTracer();



    void render(Image *_image);

private:
    BasicCamera _camera;


    color &cast(Ray &ray, color &c);
};

#endif // RAYTRACER_H
