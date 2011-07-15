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

#include "vec_func.h"

namespace rt
{

    /**
     *  \brief Adds two vec4s.
     *
     *      The method adds two vec4 objects togeather.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs + rhs.
     */
    const vec4 operator+( const vec4 &lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movaps %2, %%xmm1 \n\t"
                "addps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }


    /**
     *  \brief Adds Scalar to a vec4.
     *
     *      The method adds a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs + rhs.
     */
    const vec4 operator+( const vec4 &lhs, float rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movss %2, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "addps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }

    /**
     *  \brief Adds Scalar to a vec4.
     *
     *      The method adds a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs + rhs.
     */
    const vec4 operator+( float lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %2, %%xmm1 \n\t"
                "movss %1, %%xmm0 \n\t"
                "shufps $0x00, %%xmm0, %%xmm0 \n\t"
                "addps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }

    /**
     *  \brief subtracts two vec4s.
     *
     *      The method subs two vec4 objects togeather.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs - rhs.
     */
    const vec4 operator-( const vec4 &lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movaps %2, %%xmm1 \n\t"
                "subps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }


    /**
     *  \brief Subtracts a Scalar to a vec4.
     *
     *      The method subs a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs - rhs.
     */
    const vec4 operator-( const vec4 &lhs, float rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movss %2, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "subps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }

    /**
     *  \brief Subtracts Scalar to a vec4.
     *
     *      The method subs a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs - rhs.
     */
    const vec4 operator-( float lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %2, %%xmm1 \n\t"
                "movss %1, %%xmm0 \n\t"
                "shufps $0x00, %%xmm0, %%xmm0 \n\t"
                "subps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }



   /**
     *  \brief Multiplies two vec4s.
     *
     *      The method muls two vec4 objects togeather.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs * rhs.
     */
    const vec4 operator*( const vec4 &lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movaps %2, %%xmm1 \n\t"
                "mulps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }


    /**
     *  \brief Multiplies a Scalar to a vec4.
     *
     *      The method muls a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs * rhs.
     */
    const vec4 operator*( const vec4 &lhs, float rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movss %2, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "mulps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }

    /**
     *  \brief Subtracts Scalar to a vec4.
     *
     *      The method muls a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs * rhs.
     */
    const vec4 operator*( float lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %2, %%xmm1 \n\t"
                "movss %1, %%xmm0 \n\t"
                "shufps $0x00, %%xmm0, %%xmm0 \n\t"
                "mulps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }

   /**
     *  \brief Divides two vec4s.
     *
     *      The method divs two vec4 objects togeather.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs / rhs.
     */
    const vec4 operator/( const vec4 &lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movaps %2, %%xmm1 \n\t"
                "divps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }


    /**
     *  \brief Divides a Scalar to a vec4.
     *
     *      The method divs a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs / rhs.
     */
    const vec4 operator/( const vec4 &lhs, float rhs )
    {
        vec4 ret;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movss %2, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "divps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }

    /**
     *  \brief Divides Scalar to a vec4.
     *
     *      The method divs a Scalar to a vec4.  Uses SSE.
     *
     *  \param lhs Left hand side of operation.
     *  \param rhs Right hand side of operation.
     *  \return Returns a constant vec4 object that is the results of lhs / rhs.
     */
    const vec4 operator/( float lhs, const vec4 &rhs )
    {
        vec4 ret;
        asm(    "movaps %2, %%xmm1 \n\t"
                "movss %1, %%xmm0 \n\t"
                "shufps $0x00, %%xmm0, %%xmm0 \n\t"
                "divps %%xmm1, %%xmm0 \n\t"
                "movaps %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(lhs), "m"(rhs)
                : "xmm0", "xmm1"
           );
        return( ret );
    }



    /**
     *  \brief Computes the dot product of two vectors, uses SSE.
     *
     *      Computes the dot product of two vectors.  The dot product is computed
     *  using SEE assembly instructions.  Should be 32/64 portable.
     *
     *  \param a A constant refrence to a vector struct.
     *  \param b A constant refrence to a vector struct.
     *  \return Single-precision dot product value.
     */
    float dot( const vec4 &a, const vec4 &b )
    {
        register float ret = 0.0f;  // Used to store the return value.
        asm(    "movaps %1, %%xmm0 \n\t" //vec4 is aligned, load the two vectors
                "movaps %2, %%xmm1 \n\t"
                "mulps %%xmm1, %%xmm0 \n\t" //x*x, y*y, z*z, w*w
                "movaps %%xmm0, %%xmm1 \n\t" // copy xmm0 -> xmm1
                "shufps $0x4e, %%xmm1, %%xmm0 \n\t" // shuf 0100 1110
                "addps %%xmm1, %%xmm0 \n\t" // this add does half of the adding
                "movaps %%xmm0, %%xmm1 \n\t" // recopy
                "shufps $0x11, %%xmm1, %%xmm0 \n\t" // 0001 0001
                "addps %%xmm1, %%xmm0 \n\t"
                "movss %%xmm0, %0\n\t" // mov lowest 4bytes into ret
                : "=m"(ret)
                : "m"( a ), "m"( b )
                : "xmm0", "xmm1"
           );
        return ret;
    }

}
