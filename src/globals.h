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

#include <getopt.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

// access OpenMP Functions
#include <omp.h>

#ifndef VERSION_IFNO
#define VERSION_IFNO
    #define VERSION 0.01f
    #define VERSION_STR "0.01a"
    #define NAME "RTRT"
#endif //VERSION_INFO


#endif //H_GLOBALS

