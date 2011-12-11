
/**
  @file modules/cmdflags.cpp

  Contains the command line flags and procesing functions.

  */




#include <cmdflags.h>

// command line options
DEFINE_int32( width, 800, "Set the screen width" );
DEFINE_int32( height, 600, "Set the screen height" );
DEFINE_bool( fullscreen, false, "Set the screen to fullscreen" );
DEFINE_bool( fps, true, "Show the frame rate in window mode" );
DEFINE_int32( interval, 30, "Screen refresh interval" );

/**
  parse_commandline parses the main functions command line options
  and sets up the logger

  @param argc number of command line arguments to parse
  @param argv list of command line arguments
  */
void parse_commandline(int *argc, char ***argv)
{
    /// parse command line params
    google::SetUsageMessage( "rtrt [options]" );
    FLAGS_logtostderr = true;
    google::ParseCommandLineFlags(argc, argv, true);

    /// setup logger
    google::InitGoogleLogging( *argv[0] );
    /// setup term handler
    google::InstallFailureSignalHandler();
}

