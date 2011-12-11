/**
 *  \file   vec4.h
 *  \brief  Defines the base vector type
 *
 *      Defines the single-precision 128 bit vector struct.  This structure
 *  is used to hold 4 floats, and is used to take advantage of SSE instructions.
 *  Support functions are defined in vec_func.h
 *
 *  \author Byron Heads <bheads@emich.edu>
 *  \date   July 14, 2011
 */

#ifndef VECT4_H
#define VECT4_H

/**
 *  \struct vec4
 *  \brief  Ray-tracers four float vector.
 *
 *      Used in vec_func, and other parts if the ray-tracer.
 *  Only has constructors, operators defined in vec_func.h
 *
 */
struct vec4
{
    float x, ///< x componant of vector.
          y, ///< y componant of vector.
          z, ///< z componant of vector.
          w; ///< w componant of vector, normally this should be zero.

    /**
     *  \brief Default constructor
     *
     *      Default constructor, all values are zero
     */
    vec4()
        : x(0), y(0), z(0), w(0) {}

    /**
     *  \brief Destructor
     *
     *      Destructor, does nothing here.
     */
    ~vec4() {}

    /**
     *  \brief Four float constructor
     *
     *      Constructor taking 4 flosting point numbers.  Defaults to 0.
     */
    vec4( float _x, float _y=0, float _z=0, float _w=0 )
        : x(_x), y(_y), z(_z), w(_w) {}

    /**
     *  \brief Array constructor
     *
     *      Constructor taking an array of 4 floats.
     */
    vec4( float f[4] )
        : x(f[0]), y(f[1]), z(f[2]), w(f[3]) {}

    /**
     *  \brief Scalar constructor.
     *
     *      Constructor taking a float, all elements except get set.  If w2
     *  is true then w gets set as well, else it is set to zero.
     *
     *  \param f    Values to set x, y, z, and w if w2 is true.
     *  \param w2   If true w is set to the value of f.
     */
    vec4( float f, bool w2 = false )
        : x(f), y(f), z(f), w( w2 ? f: 0 ) {}

    /**
     *  \brief Copy Constructor
     *
     *      Constructor that copies the value of v.
     *
     *  \param v Vector refrence to copy from.
     */
    vec4( const vec4 &v )
        : x(v.x), y(v.y), z(v.z), w(v.w) {}


    /**
     *  \brief Assignment operator.
     *
     *  Assignment operator.  Copies another vec4 object.
     *
     *  \param o Object to copy;
     *  \return Refrence to self, is a copy of o
     */
    vec4 &operator=( const vec4 &o )
    {
        if( this != &o )
        {
            x = o.x;
            y = o.y;
            z = o.z;
            w = o.w;
        }
        return *this;
    }

    /**
     *  \brief Scalar assignment operator.
     *
     *   Scalar assignment operator.  Copies a scalar value.  W is copied.
     *
     *  \param v Scalar value to set vector to.
     *  \return Refrence to self, is set to v.
     */
    vec4 &operator=( const float v )
    {
        x = y = z = w = v;
        return *this;
    }


    inline vec4 &fnormalize()
    {
        asm(    "movaps %1, %%xmm0 \n\t"            // load vec into xmm0
                "movaps %%xmm0, %%xmm2 \n\t"        // save original for later use
                "mulps %%xmm0, %%xmm0 \n\t"         // square vec x*x, y*y, z*z, w*w
                "movaps %%xmm0, %%xmm1 \n\t"        // copy xmm0 to xmm1
                "shufps $0x4e, %%xmm0, %%xmm0 \n\t" // 4e 0100 1110 (1 0 3 2) xmm1   y, x, w, z
                "addps %%xmm1, %%xmm0 \n\t"         // add xmm1 to xmm0 = (xy, xy, zw, zw)
                "movaps %%xmm0, %%xmm1 \n\t"        // copy xmm0 to xmm1
                "shufps $0xb1, %%xmm0, %%xmm0 \n\t" // b1 1011 0001 (2 3 0 1) xmm1 (zw, zw, xy, xy)
                "addps %%xmm1, %%xmm0 \n\t"         // add xmm1 to xmm0 (xyzw, xyzw, xyzw, xyzw)
                "rsqrtps %%xmm0, %%xmm0 \n\t"       // take recipicle sqrt
                "mulps %%xmm2, %%xmm0 \n\t"         // multiply
                "movaps %%xmm0, %0 \n\t"
                : "=m"(*this)
                : "m"(*this)
                : "xmm0", "xmm1", "xmm2"
           );
        return(*this);
    }

    inline vec4 &normalize()
    {
        asm(    "movaps %1, %%xmm0 \n\t"            // load vec into xmm0
                "movaps %%xmm0, %%xmm2 \n\t"        // save original for later use
                "mulps %%xmm0, %%xmm0 \n\t"         // square vec x*x, y*y, z*z, w*w
                "movaps %%xmm0, %%xmm1 \n\t"        // copy xmm0 to xmm1
                "shufps $0x4e, %%xmm0, %%xmm0 \n\t" // 4e 0100 1110 (1 0 3 2) xmm1   y, x, w, z
                "addps %%xmm1, %%xmm0 \n\t"         // add xmm1 to xmm0 = (xy, xy, zw, zw)
                "movaps %%xmm0, %%xmm1 \n\t"        // copy xmm0 to xmm1
                "shufps $0xb1, %%xmm0, %%xmm0 \n\t" // b1 1011 0001 (2 3 0 1) xmm1 (zw, zw, xy, xy)
                "addps %%xmm1, %%xmm0 \n\t"         // add xmm1 to xmm0 (xyzw, xyzw, xyzw, xyzw)
                "sqrtps %%xmm0, %%xmm0 \n\t"        // take the sqrt of xmm0
                "divps %%xmm0, %%xmm2 \n\t"         // divide
                "movaps %%xmm2, %0 \n\t"
                : "=m"(*this)
                : "m"(*this)
                : "xmm0", "xmm1", "xmm2"
           );
        return(*this);
    }

    inline float length()
    {
        float ret = 0.0f;
        asm(    "movaps %1, %%xmm0 \n\t"            // load vec into xmm0
                "mulps %%xmm0, %%xmm0 \n\t"         // square vec x*x, y*y, z*z, w*w
                "movaps %%xmm0, %%xmm1 \n\t"        // copy xmm0 to xmm1
                "shufps $0x4e, %%xmm0, %%xmm0 \n\t" // 4e 0100 1110 (1 0 3 2) xmm1   y, x, w, z
                "addps %%xmm1, %%xmm0 \n\t"         // add xmm1 to xmm0 = (xy, xy, zw, zw)
                "movaps %%xmm0, %%xmm1 \n\t"        // copy xmm0 to xmm1
                "shufps $0xb1, %%xmm0, %%xmm0 \n\t" // b1 1011 0001 (2 3 0 1) xmm1 (zw, zw, xy, xy)
                "addps %%xmm1, %%xmm0 \n\t"         // add xmm1 to xmm0 (xyzw, xyzw, xyzw, xyzw)
                "sqrtss %%xmm0, %%xmm0 \n\t"        // take the sqrt of xmm0
                "movss %%xmm0, %0 \n\t"
                : "=m"(ret)
                : "m"(*this)
                : "xmm0", "xmm1"
           );
        return(ret);
    }
}__attribute__((aligned(16))); ///< Make sure this is 16 byte aligned. Can use movaps

/**
 *  \typedef vec4 color
 *   rtrt Colors are also vectors
*/
typedef vec4 color;

typedef vec4 vec;

struct Ray
{
    Ray()
        :_o(),
         _d()
    {}

    Ray(vec4 o, vec4 d)
        : _o(o),
          _d(d)
    {}

    vec4 _o, _d;
};

#endif
