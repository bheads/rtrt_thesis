#ifndef CMDFLAGS_H
#define CMDFLAGS_H


// include google flags
#include <gflags/gflags.h>
#include <glog/logging.h>

DECLARE_bool (fullscreen);
DECLARE_bool (fps);
DECLARE_int32 (width);
DECLARE_int32 (height);
DECLARE_int32 (interval);

void parse_commandline (int *argc, char ***argv);

#endif // CMDFLAGS_H
