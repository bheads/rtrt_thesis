#include "image.h"

#include <modules/color.h>

Image::Image()
    : _width(0), _height(0), _data(NULL), ready(false)
{
}

Image::Image(size_t w, size_t h)
    : _width(0), _height(0), _data(NULL), ready(false)
{
    create_image(w, h);
}

Image::~Image()
{
    destroy_image();
}


void Image::create_image(size_t w, size_t h)
{
    destroy_image();
    _width = w;
    _height = h;
    LOG(INFO) << "Creating new image: " << w << "x" << h;
    _data = new iColor[_width * _height];
    ready = _data != NULL;
    fill_with_color(0);
}

void Image::destroy_image()
{
    if(ready || _data != NULL)
    {
        delete[] _data;
    }
    ready = false;
    _data = NULL;
}

void Image::fill_with_color(boost::uint8_t r, boost::uint8_t g, boost::uint8_t b)
{
    if(!ready) return;
#pragma omp parallel for
    for(ssize_t y = 0; y < _height; ++y)
    {
        for(ssize_t x = 0; x < _width; ++x)
        {
            _data[at(x,y)].r = r;
            _data[at(x,y)].g = g;
            _data[at(x,y)].b = b;
            _data[at(x,y)].a = 0;
        }
    }
}

void Image::fill_with_color(boost::uint32_t c)
{
    if(!ready) return;
#pragma omp parallel for
    for(ssize_t y = 0; y < _height; ++y)
    {
        for(ssize_t x = 0; x < _width; ++x)
        {
            _data[at(x,y)].color = c;
        }
    }
}


void Image::fill_with_random()
{
    if(!ready) return;
#pragma omp parallel for
    for(ssize_t y = 0; y < _height; ++y)
    {
        int random_color = rand();
        for(ssize_t x = 0; x < _width; ++x)
        {
            _data[at(x,y)].color = random_color;
        }
    }
}
