#include "window.h"

Window::Window()
	: running (false), framerate (0), framecount (0), frameaverage (0), framedelta (0.0), frameupdatetime (glfwGetTime() + 1.0), frameprev (glfwGetTime()),
	  _deltaX (0.0f), _deltaY (0.0f), _deltaZ (0.0f)
{
	int major, minor, revision;
	CHECK (glfwInit() == GL_TRUE) << "Failed to initilize GLFW";
	glfwGetVersion (&major, &minor, &revision);
	LOG (INFO) << "Using GLFW verion " << major << "." << minor << "." << revision;
	windows().push_back (this);
}

Window::Window (uint32_t width, uint32_t height, bool fullscreen, std::string title, int32_t interval)
	: running (false), framerate (0), framecount (0), frameaverage (0), framedelta (0.0), frameupdatetime (glfwGetTime() + 1.0), frameprev (glfwGetTime()),
	  _deltaX (0.0f), _deltaY (0.0f), _deltaZ (0.0f)
{
	int major, minor, revision;
	glfwGetVersion (&major, &minor, &revision);
	LOG (INFO) << "Using GLFW verion " << major << "." << minor << "." << revision;
	CHECK (glfwInit() == GL_TRUE) << "Failed to initilize GLFW";
	create_window (width, height, fullscreen, title, interval);
	windows().push_back (this);
}

Window::~Window()
{
	destroy_window();
	glfwTerminate();
}

void Window::create_window (uint32_t _width, uint32_t _height, bool _fullscreen, std::string title, int32_t interval)
{
	this->_width = _width;
	this->_height = _height;
	fullscreen = _fullscreen;
	glfwOpenWindowHint (GLFW_FSAA_SAMPLES, 0); // no AA
	glfwOpenWindowHint (GLFW_WINDOW_NO_RESIZE, 1); // no resize
	LOG (INFO) << "Creating a " << (fullscreen ? "fullscreen " : "") << "window at " << _width << "x" << _height;
	CHECK (glfwOpenWindow (_width, _height, 8, 8, 8, 0, 0, 0, (fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW)) == GL_TRUE)
			<< "GLFW Failed to create our window";
	change_title (title);
	change_swap_interval (interval);
	set_handlers();
	init_gl();
	running = true;
}

void Window::change_title (std::string _title)
{
	title = _title;
	glfwSetWindowTitle (title.c_str());
}

void Window::change_swap_interval (int32_t interval)
{
	LOG (INFO) << "Setting refreash interval to " << interval;
	glfwSwapInterval (interval);
}

void Window::init_gl()
{
	glClearColor (0, 0, 0, 0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho (0, _width, _height, 0, 0, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glDisable (GL_DEPTH_TEST);
	glDisable (GL_LIGHTING);
	glDisable (GL_ALPHA);
}

void Window::update_title_with_frame_rate()
{
	std::stringstream ss;
	ss << title << " -- RT_FPS: " << PerformanceMonitor::instance().RT_FPS.rate() <<
	   " -- RPS: " << PerformanceMonitor::instance().RPS.rate();
	glfwSetWindowTitle (ss.str().c_str());
}

void Window::set_handlers()
{
	glfwSetWindowCloseCallback (&event_window_closed);
	glfwSetWindowSizeCallback (&event_window_resized);
	glfwSetWindowRefreshCallback (&event_window_refresh);
	glfwSetKeyCallback (&event_window_keypress);
}

void Window::destroy_window()
{
	if (running)
	{
		glfwCloseWindow();
	}

	running = false;
}

int32_t Window::event_window_closed()
{
	int32_t ret = GL_FALSE;
	BOOST_FOREACH (Window * win, windows())
	{
		ret = ret || win->window_closed();
	}
	return (GL_FALSE);
}

void Window::event_window_refresh()
{
	BOOST_FOREACH (Window * win, windows())
	{
		win->window_refresh();
	}
}

void Window::event_window_resized (int _width, int _height)
{
	BOOST_FOREACH (Window * win, windows())
	{
		win->window_resized (_width, _height);
	}
}

void Window::event_window_keypress (int _key, int _action)
{
	BOOST_FOREACH (Window * win, windows())
	{
		win->window_keypress (_key, _action);
	}
}


int32_t Window::window_closed()
{
	LOG (INFO) << "Got windows close event";
	running = false;
	return (GL_FALSE);
}

void Window::window_refresh()
{
	LOG (INFO) << "Got window refresh event";
}

void Window::window_resized (int _width, int _height)
{
	LOG (INFO) << "Got window resize event";
	_width = _width;
	_height = _height;
}

void Window::update_frame_rate()
{
	double frametime = glfwGetTime();
	++framecount;

	if (frametime >= frameupdatetime)
	{
		framerate = framecount;
		framecount = 0;
		frameupdatetime = frametime + 1.0f;

		if (frameaverage <= 0)
		{
			frameaverage = framerate;
		}

		frameaverage += framerate;
		frameaverage /= 2;
	}

	framedelta = frametime - frameprev;
	frameprev = frametime;
}

void Window::window_keypress (int key, int action)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESC || key == 'Q')
		{
			LOG (INFO) << "Got exit key";
			running = false;
		}
		else if (key == GLFW_KEY_LEFT)
		{
			_deltaX -= 1.0f;
		}
		else if (key == GLFW_KEY_RIGHT)
		{
			_deltaX += 1.0f;
		}
		else if (key == GLFW_KEY_UP)
		{
			_deltaY += 1.0f;
		}
		else if (key == GLFW_KEY_DOWN)
		{
			_deltaY -= 1.0f;
		}
		else if (key == '=')
		{
			_deltaZ -= 1.0f;
		}
		else if (key == '-')
		{
			_deltaZ += 1.0f;
		}
	}
	else
	{
	}
}

void Window::render_image (Image &img)
{
	glDrawPixels (img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.data());
}
