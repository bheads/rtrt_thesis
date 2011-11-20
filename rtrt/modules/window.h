#ifndef WINDOW_H
#define WINDOW_H

// C++ includes
#include <string>
#include <sstream>
#include <vector>

// Libraries
#include <boost/cstdint.hpp>
#include <boost/foreach.hpp>
#include <GL/glfw.h>

// Project
#include <cmdflags.h>
#include <modules/image.h>

class Window
{
public:
    Window();
    Window(uint32_t, uint32_t, bool, std::string, int32_t);
    ~Window();

    void create_window(uint32_t, uint32_t, bool, std::string, int32_t);
    void change_title(std::string);
    void change_swap_interval(int32_t);
    void init_gl();
    void update_title_with_frame_rate();
    void destroy_window();

    static int32_t event_window_closed();
    static void event_window_resized(int,int);
    static void event_window_refresh();
    static void event_window_keypress(int, int);

    void render_image(Image &);

    inline bool is_running() { return(running); }
    inline double delta() { return(framedelta); }

    void update_frame_rate();

    inline void clear() { glClear(GL_COLOR_BUFFER_BIT); }
    inline void update() { glfwSwapBuffers(); }

    inline uint32_t width() { return(_width); }
    inline uint32_t height(){ return(_height); }

    inline uint32_t average_framerate() { return(frameaverage); }

    inline float deltaX() { return(_deltaX);}
    inline float deltaY() { return(_deltaY);}
    inline float deltaZ() { return(_deltaZ);}
    inline void clearXY() { _deltaX = _deltaY = _deltaZ = 0.0f; }

private:
    uint32_t _width, _height;
    bool fullscreen, running;
    std::string title;

    int32_t framerate, framecount, frameaverage;
    double framedelta, frameupdatetime, frameprev;

    float _deltaX, _deltaY, _deltaZ;


    static std::vector<Window*> &windows() { static std::vector<Window*> s_vec; return(s_vec); }

    int32_t window_closed();
    void window_resized(int,int);
    void window_refresh();
    void window_keypress(int,int);


    void set_handlers();

};

#endif // WINDOW_H
