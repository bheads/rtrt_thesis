/***
 *  \file   vec_func.cpp
 *  \brief  This file will contain several vector math functions.
 *
 *  \author Byron Heads
 *  \email  bheads@emich.edu
 *  \date   July 14, 2011
 */


#include "vec_func.h" ///function prototypes, support includes

/***
 *  \brief Computes the dot product of two vectors, uses SSE.
 *
 *  \param a A constant refrence to a vector struct.
 *  \param b A constant refrence to a vector struct.
 *  \return Single-precision dot product value.
 */
float dot( const vec4 &a, const vec4 &b )
{
    register float ret = 0.0f;  /// Used to store the return value.
    asm(    "movaps %1, %%xmm0 \n\t" ///vec4 is aligned, load the two vectors
            "movaps %2, %%xmm1 \n\t"
            "mulps %%xmm1, %%xmm0 \n\t" ///x*x, y*y, z*z, w*w
            "movaps %%xmm0, %%xmm1 \n\t" /// copy xmm0 -> xmm1
            "shufps $0x4e, %%xmm1, %%xmm0 \n\t" /// shuf 0100 1110
            "addps %%xmm1, %%xmm0 \n\t" /// this add does half of the adding
            "movaps %%xmm0, %%xmm1 \n\t" /// recopy 
            "shufps $0x11, %%xmm1, %%xmm0 \n\t" /// 0001 0001 
            "addps %%xmm1, %%xmm0 \n\t"
            "movss %%xmm0, %0\n\t" /// mov lowest 4bytes into ret
            : "=m"(ret)
            : "m"( a ), "m"( b )
            : "xmm0", "xmm1"
       );
    return ret;
}

