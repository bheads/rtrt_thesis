/**
 *  \file   globals.h
 *  \brief  Header files to includes commonly used libraries.
 *
 *      Loades commonly used header files.
 *
 *  \author Byron Heads <bheads@emich.edu>
 *  \date   July 14, 2011
 */

#ifndef H_GLOBALS
#define H_GLOBALS

#include <cerrno>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cmath>
#include <inttypes.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

// access OpenMP Functions
#include <omp.h>


// running varible
extern bool running;

// program title
#define __TITLE__ "Real-Time Ray Tracer Demo"

#endif //H_GLOBALS

