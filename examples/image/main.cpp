#include <iostream>
#include <Jatta.h>
using namespace Jatta;

int main()
{
    try
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

	OpenGL::ClearErrors();
        Float2 linePositions[] = { Float2(0, 0), Float2(1, 1) };
        OpenGL::VertexArray vertexArray;
        vertexArray.Create();
        vertexArray.Bind();

        OpenGL::Buffer buffer1;
        buffer1.Create(OpenGL::GL::ARRAY_BUFFER);
        buffer1.Bind();
        buffer1.Data(4 * 2 * sizeof(Float32), linePositions, OpenGL::GL::STATIC_DRAW);

        vertexArray.AttribPointer(OpenGL::POSITION1, 2, OpenGL::GL::FLOAT, false, 0, 0);

        graphics.SetViewPort(0, 0, 640, 480);
    
        while (window.IsOpen())
        {
            Window::Update();

            graphics.Clear(Colors::red);

            shader.Begin();
            shader.SetMatrix("orthoMatrix", Matrix::MakeOrtho(0, 0, 1, 1));
            shader.SetMatrix("modelMatrix", Matrix::identity);
            shader.SetTexture("texture", texture);
            //mesh.Draw();
            OpenGL::ClearErrors();
            vertexArray.Bind();
            vertexArray.DrawArrays(OpenGL::GL::LINES, 0, 4);
            vertexArray.Unbind();
            shader.End();

            OpenGL::Test();

            graphics.Present();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
