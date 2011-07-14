/***
 *  \file   vec4.h
 *  \brief  Defines the base vector type
 *
 *  \author Byron Heads <bheads@emich.edu>
 *  \date   July 14, 2011
 */

#ifndef H_MATH_VECT4
#define H_MATH_VECT4

/***
 *  \struct vec4
 *  \brief  Ray-tracers 4 floating point vector.  Used in vec_func, and
 *          other parts if the ray-tracer.  Only has constructors, operators 
 *          defined in vec_func.
 */
struct vec4
{
    float x, y, z, w;

    vec4( float _x=0, float _y=0, float _z=0, float _w=0 )
        : x(_x), y(_y), z(_z), w(_w) {}

    vec4( float f[4] )
        : x(f[0]), y(f[1]), z(f[2]), w(f[3]) {}

    vec4( float f )
        : x(f), y(f), z(f), w(f) {}

    vec4( const vec4 &v )
        : x(v.x), y(v.y), z(v.z), w(v.w) {}

}__attribute__((aligned(16)));

#endif
