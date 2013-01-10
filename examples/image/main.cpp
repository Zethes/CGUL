#include <Jatta.h>
using namespace Jatta;

int main()
{
    WindowStyle style;
    style.title = "Jatta Window";
    style.width = 640;
    style.height = 480;
    style.backgroundColor = Colors::black;
    style.resizable = false;

    Window window;
    window.Create(style);

    Graphics graphics;
    graphics.Create(&window);

    Shader shader;
    shader.Load("screen.vert", "screen.frag");
    shader.BindAttribute(Graphics::position1, "vertPosition");
    shader.BindAttribute(Graphics::texCoord1, "vertTexCoord");

    Float2 boxPositions[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };
    Float2 boxTexCoords[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };
    SubMesh mesh;
    mesh.Setup(SubMesh::Type::QUADS, 4);
    mesh.AddBuffer(boxPositions, Graphics::position1);
    mesh.AddBuffer(boxTexCoords, Graphics::texCoord1);

    Image image;
    image.LoadPng("sky.png");
    Texture texture;
    texture.Create(image);

    graphics.SetViewPort(0, 0, 640, 480);

    while (window.IsOpen())
    {
        Window::Update();

        graphics.Clear(Colors::black);

        shader.Begin();
        shader.SetMatrix("orthoMatrix", Matrix::MakeOrtho(0, 0, 1, 1));
        shader.SetMatrix("modelMatrix", Matrix::identity);
        shader.SetTexture("texture", texture);
        mesh.Draw();
        shader.End();

        graphics.Present();
    }
}