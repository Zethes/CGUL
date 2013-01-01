#include "Primitives.h"
#include "Graphics.h"
#include <GL/glew.h>
#include "../Math/Float4.h"

static unsigned int line2DVertexArray;
static Jatta::Float2 line2DVertex[2] = {Jatta::Float2(0, 0), Jatta::Float2(0, 0)};
static Jatta::Float4 line2DColor[2] = {Jatta::Float4(0, 0, 0, 0), Jatta::Float4(0, 0, 0, 0)};
unsigned int line2DObject[2];
static unsigned int triangle2DVertexArray;
static Jatta::Float2 triangle2DVertex[3] = {Jatta::Float2(0, 0), Jatta::Float2(0, 0), Jatta::Float2(0, 0)};
static Jatta::Float4 triangle2DColor[3] = {Jatta::Float4(0, 0, 0, 0), Jatta::Float4(0, 0, 0, 0), Jatta::Float4(0, 0, 0, 0)};
unsigned int triangle2DObject[2];

static void setup()
{
    static bool done = false;
    if (!done)
    {
        glGenVertexArrays(1, &line2DVertexArray);
        glBindVertexArray(line2DVertexArray);
        glGenBuffers(2, line2DObject);
        glBindBuffer(GL_ARRAY_BUFFER, line2DObject[0]);
        glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(Jatta::Float2), (float*)line2DVertex, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(Jatta::Graphics::position1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(Jatta::Graphics::position1);
        glBindBuffer(GL_ARRAY_BUFFER, line2DObject[1]);
        glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(Jatta::Float4), (float*)line2DColor, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(Jatta::Graphics::color1, 4, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(Jatta::Graphics::color1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glGenVertexArrays(1, &triangle2DVertexArray);
        glBindVertexArray(triangle2DVertexArray);
        glGenBuffers(2, triangle2DObject);
        glBindBuffer(GL_ARRAY_BUFFER, triangle2DObject[0]);
        glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Jatta::Float2), (float*)triangle2DVertex, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(Jatta::Graphics::position1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(Jatta::Graphics::position1);
        glBindBuffer(GL_ARRAY_BUFFER, triangle2DObject[1]);
        glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Jatta::Float4), (float*)triangle2DColor, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(Jatta::Graphics::color1, 4, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(Jatta::Graphics::color1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        done = true;
    }
}

_JATTA_EXPORT void Jatta::Primitives::drawLine(Jatta::Float2 position1, Jatta::Color color1, Jatta::Float2 position2, Jatta::Color color2)
{
    setup();
    glBindVertexArray(line2DVertexArray);
    line2DVertex[0] = position1;
    line2DVertex[1] = position2;
    line2DColor[0] = Jatta::Float4(color1.r / 255.0f, color1.g / 255.0f, color1.b / 255.0f, color1.a / 255.0f);
    line2DColor[1] = Jatta::Float4(color2.r / 255.0f, color2.g / 255.0f, color2.b / 255.0f, color2.a / 255.0f);
    glBindBuffer(GL_ARRAY_BUFFER, line2DObject[0]);
    glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(Jatta::Float2), (float*)line2DVertex, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, line2DObject[1]);
    glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(Jatta::Float4), (float*)line2DColor, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
}

_JATTA_EXPORT void Jatta::Primitives::drawLine(Jatta::Float3 position1, Jatta::Color color1, Jatta::Float3 position2, Jatta::Color color2)
{
    setup();
}

_JATTA_EXPORT void Jatta::Primitives::drawTriangle(Jatta::Float2 position1, Jatta::Color color1, Jatta::Float2 position2, Jatta::Color color2, Jatta::Float2 position3, Jatta::Color color3)
{
    setup();
    glBindVertexArray(triangle2DVertexArray);
    triangle2DVertex[0] = position1;
    triangle2DVertex[1] = position2;
    triangle2DVertex[2] = position3;
    triangle2DColor[0] = Jatta::Float4(color1.r / 255.0f, color1.g / 255.0f, color1.b / 255.0f, color1.a / 255.0f);
    triangle2DColor[1] = Jatta::Float4(color2.r / 255.0f, color2.g / 255.0f, color2.b / 255.0f, color2.a / 255.0f);
    triangle2DColor[2] = Jatta::Float4(color3.r / 255.0f, color3.g / 255.0f, color3.b / 255.0f, color3.a / 255.0f);
    glBindBuffer(GL_ARRAY_BUFFER, triangle2DObject[0]);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Jatta::Float2), (float*)triangle2DVertex, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, triangle2DObject[1]);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Jatta::Float4), (float*)triangle2DColor, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}