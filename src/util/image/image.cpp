
/**
  \file image.cpp

  \brief Image class method definitions

  The Image class is used to hold the ray tracers output image.  
  The image is stored in a Color vector array.
*/

#include "image.h"


namespace rt
{

    Image::Image( size_t w, size_t h )
        : data( NULL ), width( w ), height( h )
    {
        _make( width, height );
    }

    Image::~Image()
    {
        _delete();
    }


    bool Image::_make( size_t w, size_t h )
    {
        width = w;
        height = h;
        LOG( INFO ) << "Creating a " << w << "x" << h << " render image";
        if( data != NULL ) _delete();
        data = new color[ w * h ];
        return( data != NULL );
    }

    void Image::_delete()
    {
        if( data != NULL )
        {
            LOG( INFO ) << "Deleting render image";
            delete[] data;
            data = NULL;
        }
    }


    void Image::_fill_gradiant()
    {
        LOG( INFO ) << "Filling render image with debug colors";
        for( size_t y = 0; y < height; ++y )
        {
            for( size_t x = 0; x < width; ++x )
            {
                data[ _offset( x, y ) ] = (float)y / (float)height;
            }
        }
    }

    void Image::_fill_random()
    {
        //LOG( INFO ) << "Filling render image with random debug colors";
//#pragma omp parallel for
        for( size_t y = 0; y < height; ++y )
        {
            for( size_t x = 0; x < width; ++x )
            {
                data[ _offset( x, y ) ] = (float)rand()/(float)RAND_MAX;
            }
        }
    }

    void Image::_render()
    {
        // draw the image pixels, slow....
        glDrawPixels( width, height, GL_RGBA, GL_FLOAT, data );



    }
}

