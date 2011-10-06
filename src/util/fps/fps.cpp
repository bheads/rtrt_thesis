/**
  \file Frame rate counter source file

  \brief Frame rate source
*/

#include "fps.h"


/**
  \breif Initilize FPS counter to the current time
*/
FPS::FPS() 
    : _time( glfwGetTime()), _delta( 0.0 ), _last( glfwGetTime()),
        _current( 0.0 ), _count( 0 ), _rate( 0 ), _rate_cb( NULL )
{ }

/**
  \breif Initilize FPS counter to the current time, and sets the callback

  \param cb Rate Update callback function pointer
*/
FPS::FPS( FPS_RATE_UPDATE cb ) 
    : _time( glfwGetTime()), _delta( 0.0 ), _last( glfwGetTime()),
        _current( 0.0 ), _count( 0 ), _rate( 0 ), _rate_cb( cb )
{ }

/**
  \brief Count the frame, compute frame delta time, and update _rate as needed
  \return Returns the frame delta
*/
double FPS::update()
{
    _current = glfwGetTime();
    _delta = _current - _last;
    _count++;

    if(( _current - _time ) >= 1.0 )
    {
        _rate = _count;
        _count = 0;
        _time = _current;
        if( _rate_cb != NULL )
            _rate_cb( _delta, _rate );
    }
    _last = _current;

    return _delta;
}


