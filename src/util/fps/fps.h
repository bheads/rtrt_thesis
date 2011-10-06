/**
  \file fps.h

  \breif frame counter header file

  \author Byron Heads
  \date 10/6/2011
  */

#ifndef H_UTIL_FPS
#define H_UTIL_FPS

#include <cstddef>
#include <stdint.h>

#include <GL/glfw.h>

typedef void( *FPS_RATE_UPDATE )( double, int32_t );

/**
  \breif Framte rate counting class.

  FPS counts frames on every call to update.  This is useful for computing
  the update rate per secound.  Also computes the time delta between calls
  to update.

  */
class FPS
{
    public:
        FPS();
        FPS( FPS_RATE_UPDATE );

        double update();

        /// Sets the rate update callback function
        void setCallBack( FPS_RATE_UPDATE cb ) { _rate_cb = cb; }
        /// Returns the current frame delta
        double getDelta() { return _delta; }
        /// Returns the current framte rate
        int32_t getRate() { return _rate; }

    private:
        double _time, _delta, _last, _current;
        int32_t _count, _rate;
        FPS_RATE_UPDATE _rate_cb;
};



#endif

