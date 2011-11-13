#ifndef IMAGE_H
#define IMAGE_H

// C++ includes
#include <boost/cstdint.hpp>
#include <cstdlib>

// Project includes
#include <cmdflags.h>
#include <modules/vec4.h>
#include <modules/vec_func.h>

union iColor
{
    boost::uint32_t color;
    struct {
        boost::uint8_t r, g, b, a;
    };
};

class Image
{
public:
    Image();
    Image(size_t, size_t);
    ~Image();

    void create_image(size_t, size_t);
    void destroy_image();

    void fill_with_color(boost::uint8_t, boost::uint8_t, boost::uint8_t);
    void fill_with_color(boost::uint32_t);
    void fill_with_random();


    inline boost::uint32_t width() { return(_width); }
    inline boost::uint32_t height() { return(_height); }
    inline iColor *data() { return(_data); }
    inline size_t at(size_t x, size_t y) { return((y * _width) + x); }

    //void set(size_t , size_t, color);

    inline void set(size_t x, size_t y, color c)
    {
        static float zero = 0.0f, one = 1.0f, conv = 255.0f;

        if(!ready) return;
        asm(    "movaps %1, %%xmm0 \n\t"
                "movss %2, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "minps %%xmm1, %%xmm0 \n\t"   // clamp min to 0.
                "movss %3, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "maxps %%xmm1, %%xmm0 \n\t"   // clamp max to 1.0
                "movss %4, %%xmm1 \n\t"
                "shufps $0x00, %%xmm1, %%xmm1 \n\t"
                "mulps %%xmm1, %%xmm0\n\t"   // multiply by 255
                "movaps %%xmm0, %0 \n\t"
                : "=m"(c)
                : "m"(c), "m"(one), "m"(zero), "m"(conv)
                : "xmm0", "xmm1"
           );
        iColor *p = &(_data[at(x,y)]);
        p->r = (uint8_t)c.x;
        p->g = (uint8_t)c.y;
        p->b = (uint8_t)c.z;
    }


private:
    boost::uint32_t _width, _height;
    iColor *_data;
    bool ready;
};

#endif // IMAGE_H
