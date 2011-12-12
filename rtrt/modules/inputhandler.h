#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
public:
    InputHandler();

    virtual void key_press(int key, int action) = 0;
};

#endif // INPUTHANDLER_H
