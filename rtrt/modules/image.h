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

    void set(size_t , size_t, color);
private:
    boost::uint32_t _width, _height;
    iColor *_data;
    bool ready;
};

#endif // IMAGE_H
