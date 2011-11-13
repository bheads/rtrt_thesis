#ifndef COLOR_H
#define COLOR_H

#include <modules/vec4.h>


/**
  \brief Clamp a color to min and max values

        Clamps a color vector to a set min and max value.  This is used
    to clamp a color to be used for rendering.

    \param c Color to clamp
    \param min Min clamp value
    \param max Max clamp value
    \returns refrence to clamped color
*/
inline color &clamp( color &c, const float min = 0, const float max = 1.0 )
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

#endif // COLOR_H
