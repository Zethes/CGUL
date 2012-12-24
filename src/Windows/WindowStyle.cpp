#include "WindowStyle.h"

Jatta::WindowStyle::WindowStyle()
{
    this->title = "";
    this->backgroundColor = Color(255, 255, 255);
    this->width = 100;
    this->height = 100;
    this->resizable = true;
}

Jatta::WindowStyle::WindowStyle(const WindowStyle& style)
{
    this->title = style.title;
    this->backgroundColor = style.backgroundColor;
    this->width = style.width;
    this->height = style.height;
    this->resizable = style.resizable;
}

Jatta::WindowStyle::WindowStyle(const std::string& title, Color backgroundColor, unsigned int width, unsigned int height, bool resizable)
{
    this->title = title;
    this->backgroundColor = backgroundColor;
    this->width = width;
    this->height = height;
    this->resizable = resizable;
}
