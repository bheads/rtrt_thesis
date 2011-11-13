
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
#include <modules/image.h>

void render(Image *back_p);

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

#pragma omp parallel
    {


#pragma omp single nowait
        {
            while(win.is_running())
            {
                win.update_frame_rate();
                render(back_p);
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
    front.destroy_image();
    back.destroy_image();
    win.destroy_window();

    return(0);
}

void render(Image *back_p)
{
#pragma omp parallel for
    for(ssize_t y = 0; y < back_p->height(); ++y)
    {
        for(ssize_t x = 0; x < back_p->width(); ++x)
        {
            back_p->set(x,y,color((float)omp_get_thread_num()/(float)omp_get_num_threads(),0,0));
        }
    }
}
