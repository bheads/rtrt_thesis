/**
 *  \file   vec_func.h
 *  \brief Prototypes for vector functions.
 *
 *      Prototypes for vector functions.
 *
 *  \see vec_func.cpp
 *
 *  \author Byron Heads <bheads@emich.edu>
 */


#ifndef VECT_FUNC_H
#define VECT_FUNC_H

#include <modules/vec4.h>

// Addition
const vec4 operator+ (const vec4 &, const vec4 &);
const vec4 operator+ (const vec4 &, float);
const vec4 operator+ (float, const vec4 &);
const vec4 operator+ (const vec4 &);
vec4 &operator += (vec4 &, const vec4 &);
vec4 &operator += (vec4 &, float);

// Subtraction
const vec4 operator- (const vec4 &, const vec4 &);
const vec4 operator- (const vec4 &, float);
const vec4 operator- (float, const vec4 &);
const vec4 operator- (const vec4 &);
vec4 &operator -= (vec4 &, const vec4 &);
vec4 &operator -= (vec4 &, float);
vec4 &sub (const vec4 &a, const vec4 &b, vec4 &v);

// Multiplication
const vec4 operator* (const vec4 &, const vec4 &);
const vec4 operator* (const vec4 &, float);
const vec4 operator* (float, const vec4 &);
vec4 &operator *= (vec4 &, const vec4 &);
vec4 &operator *= (vec4 &, float);

// Division
const vec4 operator/ (const vec4 &, const vec4 &);
const vec4 operator/ (const vec4 &, float);
const vec4 operator/ (float, const vec4 &);
vec4 &operator /= (vec4 &, const vec4 &);
vec4 &operator /= (vec4 &, float);

// Products
float dot (const vec4 &, const vec4 &);  ///< Compute dot product of teo vectors
const vec4 cross (const vec4 &, const vec4 &);  ///< compute cross product as a new vec
vec4 &cross (const vec4 &, const vec4 &, vec4 &); ///< compute cross into input param

//color ops

// color clamping
//color &clamp( color &, const float = 0.0, const float = 1.0 ); /// < Clamp a color to a given value
const color clamped (const color &, const float = 0.0, const float = 1.0);  /// < Return a clamped copy
color &clamp (color &, const float = 0.0, const float = 1.0);  /// < clamp a color

// Ray ops
const vec4 at (const Ray &r, float dist);
vec4 &at (const Ray &r, float dist, vec &v);

#endif

