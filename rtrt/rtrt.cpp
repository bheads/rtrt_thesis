
/**
  @file rtrt.cpp

  @brief Real-time ray tracer main

  The real-time ray tracer is a thesis research project in the algorithms and data structures
  need to create a real-time ray tracing render.

  @author Byron Heads <bheads@emich.edu>
  */

// C++ includes
#include <boost/cstdint.hpp>

// Projects includes
#include <cmdflags.h>
#include <modules/window.h>
#include <modules/image.h>

int main(int argc, char *argv[])
{
    // process command line
    parse_commandline(&argc, &argv);

    LOG(INFO) << "rtrt init";
    Window win(FLAGS_width, FLAGS_height, FLAGS_fullscreen, "Real-time Ray Tracer", FLAGS_interval);
    Image img(win.width(), win.height()); // create the image

    while( win.is_running())
    {
        win.clear(); // clear the back buffer, also computer frame rate and frame delta
        if(FLAGS_fps) win.update_title_with_frame_rate(); // show the frame rate in the window title

 #pragma omp parallel for
        for(size_t y = 0; y < img.height(); ++y)
        {
            for(size_t x = 0; x < img.width(); ++x)
            {
                img.set(x,y,color(1,0,0));
            }
        }


        win.render_image(img); // render the image to the back buffer

        win.update(); // swap the back buffer with the front buffer
    }

    LOG(INFO) << "shutting down";
    img.destroy_image();
    win.destroy_window();

    return(0);
}
