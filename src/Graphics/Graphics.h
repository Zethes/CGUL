//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Windows/Window.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Graphics
    {
        static Graphics* current;

        std::shared_ptr<Jatta::Window> window;

    #   ifdef WINDOWS
        _JATTA_PIXELFORMATDESCRIPTOR pfd;
        _JATTA_HDC deviceContext;
        unsigned int pixelFormat;
        _JATTA_HGLRC renderContext;
    #   endif

    #   ifdef LINUX
        _JATTA_GLXCONTEXT context;
    #   endif
    public:
        static const unsigned int position1 =  0, position2 =  1, position3 =  2, position4 =  3;
        static const unsigned int color1    =  4, color2    =  5, color3    =  6, color4    =  7;
        static const unsigned int texCoord1 =  8, texCoord2 =  9, texCoord3 = 10, texCoord4 = 11;
        static const unsigned int normal1   = 12, normal2   = 13, normal3   = 14, normal4   = 15;

        static Graphics* getCurrent();

        Graphics(std::shared_ptr<Jatta::Window> window);
        ~Graphics();

        std::shared_ptr<Jatta::Window> getWindow();

        void makeCurrent();

        void clear(const Jatta::Color& color);

        void present();

        void setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    };
}

#include "../External/Undefines.h"