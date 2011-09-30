/**
 *  \mainpage Real-Time Ray-Trace
 *  
 *      Real-Time Ray-Tracer is an experimental ray-tracer written in C++
 *  using SEE amd OpenMP to optimize the rendering.  The goal of the 
 *  the project is to develop a demo that achieves 30fps at 800x600.
 */

/**
 *  \file   main.cpp
 *  \brief RTRT main entry point.
 *
 *      Program entry point.  This is the program.
 *
 *  \author Byron Heads <bheads@emich.edu>
 *  \date   July 14, 2011
 */


#include "globals.h"
// running
bool running = true;

// googles logger
#include <glog/logging.h>
// google gflags
#include <gflags/gflags.h>

// glfw
#include <GL/glfw.h>

// handlers
#include "util/handlers/handlers.h"
#include "util/gl/gl.h"

/// proto-type for real main function
int rtrt_main();

// command line options
DEFINE_int32( width, 800, "Set the screen width" );
DEFINE_int32( height, 600, "Set the screen height" );
DEFINE_bool( fullscreen, false, "Set the screen to fullscreen" );
DEFINE_int32( interval, 30, "Screen refresh interval" );

/**
 *  \brief Program entry point.  
 * 
 *  Creates the render and rendering environment.
 *
 *  \param  argc    Argument count.
 *  \param  argv    List of argument string, parsed with getopt.
 *  \return Returns 0 on a clean exit, any errors will be written to cerr.
 */
int main( int argc, char **argv )
{
    /// programs return code
    int retcode = 1;

    /// parse command line params
    google::SetUsageMessage( "rtrt [options]" );
    FLAGS_logtostderr = true;
    google::ParseCommandLineFlags(&argc, &argv, true);

    /// setup logger
    google::InitGoogleLogging( argv[0] );
    /// setup term handler
    google::InstallFailureSignalHandler();

    LOG(INFO) << "starting";

    // call the real main function in a try catch to handle 
    // uncaught exceptions.
    try {
        retcode = rtrt_main();
    } catch( std::string str ) {
        LOG( FATAL ) << "Uncaught string exception: " << str;
    } catch( char *str ) {
        LOG( FATAL ) << "Uncaught string exception: " << str;
    } catch( int code ) {
        LOG( FATAL ) << "Uncaught int exception: " << code;
    }

    LOG(INFO) << "finnished: returning " << retcode;

    return( retcode );
}

/**
 * \brief Programs real main function.
 *
 *  rtrt_main is the real main, it is called this way as a way to trap any
 *  exceptions.  This functions creates all of the required objects and starts
 *  the ray tracer.
 *
 *  \return Returns 0 on succes, non-zero on failure.
 */
int rtrt_main()
{
    // create the glfw windows
    CHECK( create_window() == GL_TRUE ) << "Failed to create the glfw window";

    // inilize openGL
    CHECK( gl_init() == GL_TRUE ) << "Failed to initilize OpenGL";

    // setup frame rate counting varibles
    double fps_time = glfwGetTime(), fps_delta = 0.0f, 
           fps_last = glfwGetTime(), fps_current;
    int fps_count = 0, fps_rate = 0; 
    char title[1024];

    // create main loop
    while( running )
    {
        // compute fps and frame offset
        fps_current = glfwGetTime();
        fps_delta = fps_current - fps_last;
        fps_count++;
        if( fps_current - fps_time >= 1.0 )
        {
            fps_rate = fps_count;
            fps_count = 0;
            fps_time = fps_current;
            sprintf( title, "%s (%d)", __TITLE__, fps_rate );
            glfwSetWindowTitle( title );
        }
        fps_last = fps_current;

        /// clear the screen
        glClear( GL_COLOR_BUFFER_BIT );



        // update screen, poll IO
        glfwSwapBuffers();
    }

    // clean up glfw window
    CHECK( destroy_window() == GL_TRUE ) << "Failed to destroy glfw window";
    return( 0 );
}

