
#ifndef H_HANDLERS
#define H_HANDLERS

#include "../../globals.h"

#include <GL/glfw.h>
#include <glog/logging.h>

/// gets the close signal
int GLFWCALL close_handler();

/// gets the key pressed handler
void GLFWCALL key_handler( int key, int action );


#endif

