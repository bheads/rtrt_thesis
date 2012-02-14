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
		RayTracer (World &world);



		void render (Image *_image);

	private:
		BasicCamera _camera;
		World &_world;

		float _aa_x, _aa_y;

		color cast (Ray &ray, int32_t level = 1, int32_t max_level = 2);
};

#endif // RAYTRACER_H
