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


#ifndef H_MATH_VECT_FUNC
#define H_MATH_VECT_FUNC

#include "../../globals.h"
#include "vec4.h"

namespace rt
{

    // Addition
    const vec4 operator+( const vec4 &, const vec4 & );
    const vec4 operator+( const vec4 &, float );
    const vec4 operator+( float, const vec4 & );
    const vec4 operator+( const vec4 & );
    vec4 & operator +=( vec4 &, const vec4 & );
    vec4 & operator +=( vec4 &, float );

    // Subtraction
    const vec4 operator-( const vec4 &, const vec4 & );
    const vec4 operator-( const vec4 &, float );
    const vec4 operator-( float, const vec4 & );
    const vec4 operator-( const vec4 & );
    vec4 & operator -=( vec4 &, const vec4 & );
    vec4 & operator -=( vec4 &, float );

    // Multiplication
    const vec4 operator*( const vec4 &, const vec4 & );
    const vec4 operator*( const vec4 &, float );
    const vec4 operator*( float, const vec4 & );
    vec4 & operator *=( vec4 &, const vec4 & );
    vec4 & operator *=( vec4 &, float );

    // Division
    const vec4 operator/( const vec4 &, const vec4 & );
    const vec4 operator/( const vec4 &, float );
    const vec4 operator/( float, const vec4 & );
    vec4 & operator /=( vec4 &, const vec4 & );
    vec4 & operator /=( vec4 &, float );


    // Products
    float dot( const vec4 &, const vec4 & ); ///< Compute dot product of teo vectors
    const vec4 cross( const vec4 &, const vec4 & ); ///< compute cross product as a new vec
    vec4 &cross( vec4 &, const vec4 &, const vec4 & );///< compute cross into input param 

}

#endif
