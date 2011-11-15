
/**
  @file rtrt.cpp

  @brief Real-time ray tracer main

  The real-time ray tracer is a thesis research project in the algorithms and data structures
  need to create a real-time ray tracing render.

  @author Byron Heads <bheads@emich.edu>
  */

// C includes
#include <omp.h>

// C++ includes
#include <boost/cstdint.hpp>

// Projects includes
#include <cmdflags.h>
#include <modules/window.h>
//#include <modules/image.h>
#include <raytracer.h>
#include <world.h>

int main(int argc, char *argv[])
{
    omp_set_nested(1);
    omp_set_num_threads(8);

    // process command line
    parse_commandline(&argc, &argv);

    LOG(INFO) << "rtrt init";
    Window win(FLAGS_width, FLAGS_height, FLAGS_fullscreen, "Real-time Ray Tracer", FLAGS_interval);
    Image front(win.width(), win.height()), back(win.width(), win.height()); // create the images
    Image *front_p = &front, *back_p = &back;

    RayTracer rt(win.width(), win.height());
    World world;

    world.add_sphere(0.5, 0.5, 600, 100, color(0,1,0));
    world.add_sphere(0.5, 0.5, -600, 100, color(0,0,1));
    world.add_sphere(-1, 3, -10, 3, color(0,0,1));
    world.add_sphere(0, 0, -20000, 5, color(1,0,0));


#pragma omp parallel
    {


#pragma omp single nowait
        {
            while(win.is_running())
            {
                win.update_frame_rate();
                rt.render(back_p, world);
                // swap buffers
                std::swap(front_p, back_p);
            }
        }

#pragma omp master
        {
            while(win.is_running())
            {
                // main rendering loop, keep rendering the front buffer
                win.clear(); // clear the render windows back buffer
                if(FLAGS_fps) win.update_title_with_frame_rate(); // show the frame rate in the window title
                win.render_image(*front_p); // render the image to the back buffer
                win.update(); // swap the back buffer with the front buffer
            }
        }
    }

    LOG(INFO) << "shutting down";
    LOG(INFO) << "Average frame rate was " << win.average_framerate();
    front.destroy_image();
    back.destroy_image();
    win.destroy_window();

    return(0);
}


