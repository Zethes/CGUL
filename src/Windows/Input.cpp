#include "Input.h"
#include <cstring>

Jatta::Input::Input(Window* window)
{
    this->window = window;
    memset(this->keyData, 0, 256);
}

bool* Jatta::Input::getKeyData()
{
    return this->keyData;
}

bool Jatta::Input::isKeyDown(unsigned char key)
{
    return this->keyData[key];
}

bool Jatta::Input::isKeyPressed(unsigned char key)
{
}

bool Jatta::Input::isKeyReleased(unsigned char key)
{
}