#ifndef SPHERE_H
#define SPHERE_H


#include <cmath>

#include <cmdflags.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>
#include <modules/objects/object.h>
#include <modules/random.h>

class Sphere : public Object
{
	public:
		Sphere();
		Sphere (const vec &pos, float r, const color &c);
		~Sphere();

		virtual float collision (const Ray &ray, float max);
		virtual bool is_light()
		{
			return false;
		}
		virtual vec &at (const Ray &ray, float dist, vec &v);
		virtual float vec_to (const vec &from, const vec &to, vec &v);
		virtual const vec &center()
		{
			return (_pos);
		}
		virtual const color &get_color()
		{
			return (_c);
		}
		virtual vec &normal (const vec &at, vec &N);

		virtual inline float diffuse()
		{
			return _diffuse;
		}
		virtual inline float specular()
		{
			return _specular;
		}
		virtual inline float reflection()
		{
			return _reflection;
		}
	protected:
		vec _pos;
		float _r, _r2;
		color _c;
		float _diffuse, _specular, _reflection;
};

#endif // SPHERE_H
