

#include "gl.h"
#include "../handlers/handlers.h"

bool create_window()
{

    int major, minor, rev;
    glfwGetVersion( &major, &minor, &rev );
    LOG( INFO ) << "Using glfw " << major << "." << minor << "." << rev;
    CHECK( glfwInit() == GL_TRUE ) << "Failed to initilize glfw: ";
    
    // create the main window, this needs to be updated with command line options
    LOG(INFO) << "Creating a " << ( FLAGS_fullscreen ? "fullscreen" : "window"  ) <<
        " app at " << FLAGS_width << "x" << FLAGS_height;
    CHECK( glfwOpenWindow( FLAGS_width, FLAGS_height, 8, 8, 8, 0, 0, 0, 
                ( FLAGS_fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW )) == GL_TRUE )
        << "Failed to create a window";
    glfwSetWindowTitle( __TITLE__ );

    // set swapInterval
    LOG(INFO) << "Setting refreash interval to " << FLAGS_interval;
    glfwSwapInterval( FLAGS_interval );

    // set close handler
    glfwSetWindowCloseCallback( close_handler );
    // set key handler
    glfwSetKeyCallback( key_handler );

    return( GL_TRUE );
}

