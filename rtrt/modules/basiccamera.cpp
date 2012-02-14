#include "basiccamera.h"

BasicCamera::BasicCamera (uint32_t width, uint32_t height)
	: _width (width),
	  _height (height),
	  _C (0, 0, -250),
	  _p (0, 0, 1),
	  _u (-1, 0, 0),
	  _v (0, 1, 0),
	  _f (1.0f),
	  _a (_f),
	  _Sx (1.0f),
	  _Sy (1.0f),
	  _aspect ( (float) _width / _height),
	  _aspect_2 (_aspect / 2),
	  _width_2 (_width / 2),
	  _height_2 (_height / 2)
{
}


Ray &BasicCamera::get_ray (Ray &ray, float x, float y)
{
	x = ( (x - _width_2) / _width_2) * _aspect_2;
	y = ( (y - _height_2) / _height_2) * 0.5f;
	ray._o = _C;
	ray._d.x = x;
	ray._d.y = y;
	ray._d.z = _f;
	ray._d.w = 0.0f;
	ray._d.normalize();
	return (ray);
}


