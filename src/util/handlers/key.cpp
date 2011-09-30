

#include "handlers.h"


/**
 *  \brief Handles the key pressed/released events
 *
 *      This callback is called on each key press.
 *  currently Escape and Q set running to false.
 */

void GLFWCALL key_handler( int key, int action )
{

    if( key == GLFW_KEY_ESC || key == 'Q' )
    {
        LOG(INFO) << "Exit key pressed";
        running = false;
    }
}

