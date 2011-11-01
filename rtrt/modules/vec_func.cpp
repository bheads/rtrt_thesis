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
 *  \brief Uniary plus.
 *
 *      Uniary plus, returns a copy of o.
 *
 *  \param o Object to copy
 *  \return Returns a constant vec4 object that is the results of +o
 */
const vec4 operator+( const vec4 &o )
{
    return( vec4( o ));
}


/**
 *  \brief Adds two vec4s.
 *
 *      The method adds two vec4 objects togeather.  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs + rhs.
 */
vec4 & operator+=( vec4 &lhs, const vec4 &rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movaps %2, %%xmm1 \n\t"
            "addps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
}

/**
 *  \brief Asss a vec4 by a scalar.
 *
 *      the method adds a vec4 with a scalar  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs + rhs.
 */
vec4 & operator+=( vec4 &lhs, float rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movss %2, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "addps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
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
 *  \brief Uniary minus
 *
 *      Uniary minus, returns a copy of o but negated
 *
 *  \param o Object to copy and negate
 *  \return Returns a constant vec4 object that is the results of -o
 */
const vec4 operator-( const vec4 &o )
{
    vec4 ret;
    asm(    "movaps %1, %%xmm1 \n\t"
            "xorps %%xmm0, %%xmm0 \n\t"
            "subps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(ret)
            : "m"(o)
            : "xmm0", "xmm1"
       );
    return( ret );
}

/**
 *  \brief  Subs two vec4s.
 *
 *      The method subs two vec4 objects togeather.  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs - rhs.
 */
vec4 & operator-=( vec4 &lhs, const vec4 &rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movaps %2, %%xmm1 \n\t"
            "subps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
}

/**
 *  \brief  Subs a vec4 by a scalar.
 *
 *      the method subs a vec4 with a scalar  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs - rhs.
 */
vec4 & operator-=( vec4 &lhs, float rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movss %2, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "subps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
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
 *  \brief  muls two vec4s.
 *
 *      the method muls two vec4 objects togeather.  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs * rhs.
 */
vec4 & operator*=( vec4 &lhs, const vec4 &rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movaps %2, %%xmm1 \n\t"
            "mulps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
}

/**
 *  \brief  Muls a vec4 by a scalar.
 *
 *      the method mul a vec4 with a scalar  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs * rhs.
 */
vec4 & operator*=( vec4 &lhs, float rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movss %2, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "mulps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
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
 *  \brief  Divs two vec4s.
 *
 *      the method divs two vec4 objects togeather.  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs / rhs.
 */
vec4 & operator/=( vec4 &lhs, const vec4 &rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movaps %2, %%xmm1 \n\t"
            "divps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
}

/**
 *  \brief  Divs a vec4 by a scalar.
 *
 *      the method divs two vec4 objects togeather.  Uses SSE.
 *
 *  \param lhs Left hand side of operation.
 *  \param rhs Right hand side of operation.
 *  \return Returns lhs / rhs.
 */
vec4 & operator/=( vec4 &lhs, float rhs )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movss %2, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "divps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(lhs)
            : "m"(lhs), "m"(rhs)
            : "xmm0", "xmm1"
       );
    return( lhs );
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
    float ret = 0.0f;  // Used to store the return value.
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

/**
 *  \brief Compute the cross product of vec4 a and b, returns a const vec4.
 *
 *      This vecrion of cross produces a copy of a new cross product.  This is
 *  a simpler way to use the cross product, but is slow since it makes copies.
 *  For real-time usage, use the other cross function.
 *
 *  \param a First vec4 of the cross product.
 *  \param b Secound vec4 in the cross product.
 *  \return Returns a const copy of the cross product vec4.
 */
const vec4 cross( const vec4 &a, const vec4 &b )
{
    /*
    shufps XMM0, XMM0, 0xD8;
    shufps XMM1, XMM1, 0xE1;
    mulps XMM0, XMM1;
    shufps XMM2, XMM2, 0xE1;
    shufps XMM3, XMM3, 0xD8;
    mulps XMM2, XMM3;
    subps XMM0, XMM2;
    movups t, XMM0;
     */
    vec4 ret;
    asm(    "movaps %1, %%xmm0 \n\t"
            "movaps %2, %%xmm1 \n\t"
            "movaps %%xmm0, %%xmm2 \n\t"
            "movaps %%xmm1, %%xmm3 \n\t"
            "shufps $0xC9, %%xmm0, %%xmm0 \n\t" // y z x w 1001 1100 9C
            "shufps $0xD2, %%xmm1, %%xmm1 \n\t" // z x y w 0111 1000 78
            "shufps $0xD2, %%xmm2, %%xmm2 \n\t" // 3 0 2 1 1100 1001 C9
            "shufps $0xC9, %%xmm3, %%xmm3 \n\t" // 3 1 0 2 1101 0010 D2
            "mulps %%xmm1, %%xmm0 \n\t"
            "mulps %%xmm3, %%xmm2 \n\t"
            "subps %%xmm2, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(ret)
            : "m"( a ), "m"( b )
            : "xmm0", "xmm1", "xmm2", "xmm3"
       );
    return( ret );
}

/**
 *  \brief Compute the cross product of vec4 a and b, puts the result in dest.
 *
 *      Computes the cross product of a and b.  The result is stored in dest vec4.
 *  This function if preferred over the other cross product function.  This one is
 *  faster as it avoids extra copying.
 *
 *  \param dest Holds the result of the cross product of a and b
 *  \param a First vec4 of the cross product.
 *  \param b Secound vec4 in the cross product.
 *  \return Returns the refrence to dest, useful for passing into other functions.
 */
vec4 &cross( vec4 &dest, const vec4 &a, const vec4 &b )
{

    return( dest );
}


/**
  \brief Clamp a color to min and max values

        Clamps a color vector to a set min and max value.  This is used
    to clamp a color to be used for rendering.

    \param c Color to clamp
    \param min Min clamp value
    \param max Max clamp value
    \returns refrence to clamped color
*/
color &clamp( color &c, const float min, const float max )
{
    asm(    "movaps %1, %%xmm0 \n\t"
            "movss %2, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "minps %%xmm1, %%xmm0 \n\t"
            "movss %3, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "maxps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(c)
            : "m"(c), "m"(max), "m"(min)
            : "xmm0", "xmm1"
       );
    return( c );
}

/**
  \brief Clamp a copied color to min and max values

        Clamps a color vector to a set min and max value.  This is used
    to clamp a color to be used for rendering.

    \param c Color to clamp
    \param min Min clamp value
    \param max Max clamp value
    \returns refrence to copied clamped color
*/
const color clamped( const color &c, const float min, const float max )
{
    color ret;
    asm(    "movaps %1, %%xmm0 \n\t"
            "movss %2, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "minps %%xmm1, %%xmm0 \n\t"
            "movss %3, %%xmm1 \n\t"
            "shufps $0x00, %%xmm1, %%xmm1 \n\t"
            "maxps %%xmm1, %%xmm0 \n\t"
            "movaps %%xmm0, %0 \n\t"
            : "=m"(ret)
            : "m"(c), "m"(max), "m"(min)
            : "xmm0", "xmm1"
       );
    return( ret );
}

