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

#ifndef H_MATH_VECT4
#define H_MATH_VECT4

namespace rt
{

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
         *  \brief Four float constructor
         *
         *      Constructor taking 4 flosting point numbers.  Defaults to 0.
         */
        vec4( float _x=0, float _y=0, float _z=0, float _w=0 )
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

    }__attribute__((aligned(16)));

    /**
     *  \typedef vec4 color
     *   rtrt Colors are also vectors
    */
    typedef vec4 color;

}

#endif
