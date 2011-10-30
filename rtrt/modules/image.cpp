#include "image.h"

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
    for(size_t y = 0; y < _height; ++y)
    {
        for(size_t x = 0; x < _width; ++x)
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
    for(size_t y = 0; y < _height; ++y)
    {
        for(size_t x = 0; x < _width; ++x)
        {
            _data[at(x,y)].color = c;
        }
    }
}


void Image::fill_with_random()
{
    if(!ready) return;
    for(size_t y = 0; y < _height; ++y)
    {
        for(size_t x = 0; x < _width; ++x)
        {
            _data[at(x,y)].color = rand();
        }
    }
}

void Image::set(size_t x, size_t y, color c)
{
    if(!ready) return;
    clamp(c);
    _data[at(x,y)].r = c.x*255;
    _data[at(x,y)].g = c.y*255;
    _data[at(x,y)].b = c.z*255;
    _data[at(x,y)].a = 0;
}
