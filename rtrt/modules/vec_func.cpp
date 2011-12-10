/**
 *  \file   vec_func.cpp
 *  \brief  This file contain several vector math functions.
 *
 *      This files contains all of the vector functions.  These functions
 *  are used to compute the core elements of the ray-tracer.  Hence these 
 *  functions need to be fast.  Most functions are written in assembly using
 *  SSE.
 *
 *      The vector type is defined in vec4.h.  Vectors will also be used to
 *  hold color information.  Thus this file contains color functions as well.
 *
 *  \author Byron Heads <bheads@emich.edu>
 *  \date   July 14, 2011
 * 
 *  \todo Add cross product
 *  \todo Add Triple product
 *  \todo Add vector operations
 *  \todo Add color operations
*/

#include <modules/vec_func.h>



const vec4 at(const Ray &r, float dist)
{
    return( r._o + (dist * r._d));
}
