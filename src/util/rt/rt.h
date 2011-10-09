/**
  \brief ray tracer engine

  The ray tracer creates the rendered image.


  */


#ifndef H_UTIL_RT
#define H_UTIL_RT

#include <glog/logging.h>

#include "../../globals.h"
#include "../math/math.h"
#include "../image/image.h"

namespace rt
{

    class RayTracer
    {
        public:
            RayTracer();
            ~RayTracer();

    
            void _render( color *, size_t, size_t );

        private:

    };

}
#endif

