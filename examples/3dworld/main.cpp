#include <Jatta.h>
#include <iostream>
using namespace Jatta;

int main()
{
    WindowStyle style;
    style.title = "Jatta Window";
    style.width = 640;
    style.height = 480;
    style.backgroundColor = Colors::black;
    style.resizable = true;

    Window window;
    window.Create(style);

    OpenGL::Context context;
    context.Create(&window);

    OpenGL::Shader vertexShader, fragmentShader;
    vertexShader.Create(OpenGL::VERTEX_SHADER);
    fragmentShader.Create(OpenGL::FRAGMENT_SHADER);

    String vertexSource, fragmentSource;
    if (!File::GetText("screen.vert", &vertexSource))
    {
        std::cout << "Failed to load screen.vert." << std::endl;
        return 0;
    }
    if (!File::GetText("screen.frag", &fragmentSource))
    {
        std::cout << "Failed to load screen.frag." << std::endl;
        return 0;
    }

    vertexShader.Source(vertexSource);
    fragmentShader.Source(fragmentSource);

    vertexShader.Compile();
    fragmentShader.Compile();

    OpenGL::Program program;
    program.Create();
    program.AttachShader(vertexShader);
    program.AttachShader(fragmentShader);
    program.Link();

    std::cout << vertexShader.GetSource() << std::endl;

    /*Shader shader;
    shader.Load("screen.vert", "screen.frag");
    shader.BindAttribute(Graphics::position1, "vertPosition");
    shader.BindAttribute(Graphics::texCoord1, "vertTexCoord");*/

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

    context.Viewport(0, 0, 640, 480);
    context.ClearColor(Colors::red);

    while (window.IsOpen())
    {
        Window::Update();

        context.Clear(OpenGL::COLOR_BUFFER_BIT | OpenGL::DEPTH_BUFFER_BIT);

        program.Bind();
        //shader.SetMatrix("orthoMatrix", Matrix::MakeOrtho(0, 0, 1, 1));
        //shader.SetMatrix("modelMatrix", Matrix::identity);
        //shader.SetTexture("texture", texture);
        //mesh.Draw();
        program.Unbind();

        context.SwapBuffers();
    }
}