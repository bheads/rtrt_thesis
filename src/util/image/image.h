/**
  \file image.h
*/

#ifndef H_UTIL_IMAGE
#define H_UTIL_IMAGE


#include <glog/logging.h>

#include <GL/glfw.h>

#include "../../globals.h"
#include "../math/math.h"


namespace rt
{

    /**
      \class Image
      \brief Image container class

      The Image class holds an array of color vectors used in the ray tracer
      and then rendered to the screen.

      Images are based in 3D space.  Images start at the bottom left corener of the
      screen.  

    */
    class Image
    {
        public:
            /// Image constructor
            Image( size_t, size_t );
            /// Image destructor
            ~Image();

            /// Create the image color array
            bool _make( size_t, size_t );

            /// delete an image array
            void _delete();

            /// fill image with gradiant, debugging tool
            void _fill_gradiant();
            /// fill image with gradiant, debugging tool
            void _fill_random();

            /// get the offset into the data array from an x and y
            inline size_t _offset( size_t x, size_t y )
            {
                return(( y * width ) + x );
            }

            /// render the image to window frame buffer
            void _render();

            size_t Width() { return width; }
            size_t Height() { return height; }
            color *Data() { return data; }

        private:
            color *data; ///< Rendering image color array
            size_t width, ///< Rendering image width
                   height; ///< Rendering image height

    }; //Image
} //rt

#endif

