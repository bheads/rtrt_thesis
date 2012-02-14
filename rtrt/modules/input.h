#ifndef INPUT_H
#define INPUT_H

#include <vector>

#include <GL/glfw.h>

#include <modules/inputhandler.h>

class Input
{
	public:
		static Input &instance();

	private:
		static Input *_instance;
		static

		std::vector<InputHandler *> _handlers;


		Input();
};

#endif // INPUT_H
