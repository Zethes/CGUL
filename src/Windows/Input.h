//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Window;

    class Input
    {
        friend Window;

        Window* window;
        bool keyData[256];

        Input(Window* window);

        bool* getKeyData();
    public:
        bool isKeyDown(unsigned char key);
        bool isKeyPressed(unsigned char key);
        bool isKeyReleased(unsigned char key);
    };
}

#include "../External/Undefines.h"