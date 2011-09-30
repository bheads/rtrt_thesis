
#include "gl.h"


bool destroy_window()
{
    // clean up glfw
    glfwCloseWindow();
    glfwTerminate();

    return( GL_TRUE );
}

