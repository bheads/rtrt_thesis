

#include "rt.h"



namespace rt
{

    RayTracer::RayTracer()
    {
    }

    RayTracer::~RayTracer()
    {


    }


    void RayTracer::_render( color *img, size_t width, size_t height )
    {
#pragma omp parallel for
        for( size_t y = 0; y < height; ++y )
        {
            for( size_t x = 0; x < width; ++ x )
            {
                // get the current color
                color &c = img[ ( y * width ) + x  ];
                // set the pixel color to black
                c.x = c.y = c.z = 0.0f;
                c.z = 1.0f;
                
                // compute ray from camera through pixel


                //clamp( c ); // openGL is clamping for us
            }
        }
    }

}

