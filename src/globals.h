
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
#include <iostream>
#include <vector>

// access SIMD instructions
#include <SIMDx86/SIMDx86.h>

// access OpenMP Functions
#include <omp.h>

#ifndef VERSION_IFNO
#define VERSION_IFNO
    #define VERSION 0.01f
    #define VERSION_STR "0.01a"
    #define NAME "RTRT"
#endif //VERSION_INFO


#endif //H_GLOBALS

