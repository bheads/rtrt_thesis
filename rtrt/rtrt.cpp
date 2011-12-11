
/**
  @file rtrt.cpp

  @brief Real-time ray tracer main

  The real-time ray tracer is a thesis research project in the algorithms and data structures
  need to create a real-time ray tracing render.

  @author Byron Heads <bheads@emich.edu>
  */

// C includes
#include <omp.h>
#include <cstdlib>
#include <ctime>

// C++ includes
#include <boost/cstdint.hpp>

// Projects includes
#include <cmdflags.h>
#include <modules/window.h>

#include <raytracer.h>
#include <modules/world.h>
#include <modules/performancemonitor.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    omp_set_nested(1);
    omp_set_num_threads(16);

    // process command line
    parse_commandline(&argc, &argv);

    LOG(INFO) << "rtrt init";
    Window win(FLAGS_width, FLAGS_height, FLAGS_fullscreen, "Real-time Ray Tracer", FLAGS_interval);
    Image front(win.width(), win.height()), back(win.width(), win.height()); // create the images
    Image *front_p = &front, *back_p = &back;

    World world;
    world.fill(5, 1);
    world.demo0();
    RayTracer rt(world);

#pragma omp parallel
    {


#pragma omp single nowait
        {
            while(win.is_running())
            {
                // update frame
                PerformanceMonitor::instance().RT_FPS.count();
                //win.update_frame_rate();
                win.clearXY();

                // render the new back buffer
                rt.render(back_p);

                // swap buffers
                std::swap(front_p, back_p);
            }
        }

#pragma omp master
        {
            while(win.is_running())
            {
                // main rendering loop, keep rendering the front buffer
                PerformanceMonitor::instance().GL_FPS.count();
                win.clear(); // clear the render windows back buffer
                if(FLAGS_fps) win.update_title_with_frame_rate(); // show the frame rate in the window title
                win.render_image(*front_p); // render the image to the back buffer
                win.update(); // swap the back buffer with the front buffer
                PerformanceMonitor::instance().update();
            }
        }
    }

    LOG(INFO) << "shutting down";
    LOG(INFO) << "Average frame rate was " << win.average_framerate();
    front.destroy_image();
    back.destroy_image();
    win.destroy_window();
    LOG(INFO) << PerformanceMonitor::instance();

    return(0);
}


