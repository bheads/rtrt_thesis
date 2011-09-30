

#include "handlers.h"


/**
 *  \brief Handles the close signal
 *
 *      This is the close windows callback function.  This sets the main 
 *  running varible to false, to stop the main running loop.
 *
 *  \return Returns false, this allows the main program to exit on its own.
 */
int GLFWCALL close_handler()
{
    LOG(INFO) << "The window had been closed";
    running = false;

    return( GL_FALSE );
}

