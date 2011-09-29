

#include "init.h"

/**
 *      Initlizes OpenGL for ray tracing.
 *
 *  \return Returns GL_TRUE if there are no errors
 */
int gl_init()
{
    /// set the clear color to black, not depth bufferis needed
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    return GL_TRUE;
}

