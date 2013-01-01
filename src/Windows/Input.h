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

        _JATTA_EXPORT Input(Window* window);

        _JATTA_EXPORT bool* getKeyData();
        _JATTA_EXPORT unsigned char getKeyFromLayout(unsigned char key);
    public:
        _JATTA_EXPORT bool isKeyDown(unsigned char key);
        _JATTA_EXPORT bool isKeyPressed(unsigned char key);
        _JATTA_EXPORT bool isKeyReleased(unsigned char key);
    };
}

#include "../External/Undefines.h"
