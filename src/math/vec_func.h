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

#include "../globals.h"
#include "vec4.h"

namespace rt
{

    float dot( const vec4 &, const vec4 & ); ///< Compute dot product of teo vectors

}

#endif

