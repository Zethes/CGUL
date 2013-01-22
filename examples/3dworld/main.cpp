#include <Jatta.h>
#include <iostream>
using namespace Jatta;

Jatta::OpenGL::Program LoadShader(const String& vertex, const String& fragment)
{
    OpenGL::Shader vertexShader, fragmentShader;
    vertexShader.Create(OpenGL::GL::VERTEX_SHADER);
    fragmentShader.Create(OpenGL::GL::FRAGMENT_SHADER);

    String vertexSource, fragmentSource;
    if (!File::GetText(vertex, &vertexSource))
    {
        throw std::runtime_error("Failed to load screen.vert.");
    }
    if (!File::GetText(fragment, &fragmentSource))
    {
        throw std::runtime_error("Failed to load screen.frag.");
    }

    vertexShader.Source(vertexSource);
    fragmentShader.Source(fragmentSource);

    vertexShader.Compile();
    if (!vertexShader.GetCompileStatus())
    {
        std::ostringstream ss;
        ss << "Failed to compile vertex." << std::endl;
        ss << vertexShader.GetInfoLog() << std::endl;
        throw std::runtime_error(ss.str().c_str());
    }
    fragmentShader.Compile();
    if (!fragmentShader.GetCompileStatus())
    {
        std::ostringstream ss;
        ss << "Failed to compile fragment." << std::endl;
        ss << fragmentShader.GetInfoLog() << std::endl;
        throw std::runtime_error(ss.str().c_str());
    }

    OpenGL::Program program;
    program.Create();
    program.AttachShader(vertexShader);
    program.AttachShader(fragmentShader);
    program.BindAttribLocation(OpenGL::POSITION1, "vertPosition");
    program.BindAttribLocation(OpenGL::TEXCOORD1, "vertTexCoord");
    
    program.Link();
    if (!program.GetLinkStatus())
    {
        std::ostringstream ss;
        ss << "Failed to link program:" << std::endl;
        ss << program.GetInfoLog() << std::endl;
        throw std::runtime_error(ss.str().c_str());
    }

    program.Validate();
    if (!program.GetValidateStatus())
    {
        std::ostringstream ss;
        ss << "Failed to validate program:" << std::endl;
        ss << program.GetInfoLog() << std::endl;
        throw std::runtime_error(ss.str().c_str());
    }

    return program;
}

int main()
{
    try
    {
        // Create the window
        WindowStyle style;
        Window window;
        style.title = "Jatta Window";
        style.width = 800;
        style.height = 600;
        style.backgroundColor = Colors::black;
        style.resizable = true;
        window.Create(style);

        // Create the OpenGL context
        OpenGL::Context context;
        context.Create(&window);

        Float2 boxPositions[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };
        Float2 boxTexCoords[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };

        OpenGL::VertexArray vertexArray;
        vertexArray.Create();
        vertexArray.Bind();

        OpenGL::Buffer positionBuffer, texCoordBuffer;

        positionBuffer.Create(OpenGL::GL::ARRAY_BUFFER);
        positionBuffer.Bind();
        positionBuffer.Data(4 * 2 * sizeof(Float32), boxPositions, OpenGL::GL::STATIC_DRAW);
        vertexArray.AttribPointer(OpenGL::POSITION1, 2, OpenGL::GL::FLOAT, false, 0, 0);
        vertexArray.EnableAttribArray(OpenGL::POSITION1);

        texCoordBuffer.Create(OpenGL::GL::ARRAY_BUFFER);
        texCoordBuffer.Bind();
        texCoordBuffer.Data(4 * 2 * sizeof(Float32), boxTexCoords, OpenGL::GL::STATIC_DRAW);
        vertexArray.AttribPointer(OpenGL::TEXCOORD1, 2, OpenGL::GL::FLOAT, false, 0, 0);
        vertexArray.EnableAttribArray(OpenGL::TEXCOORD1);

        vertexArray.Unbind();

        Image image;
        image.LoadPng("sky.png");
        /*Texture texture;
        texture.Create(image);*/

        OpenGL::Texture texture;
        texture.Create(OpenGL::GL::TEXTURE_2D);
        texture.Bind();
        texture.SetTextureWrapS(OpenGL::GL::REPEAT);
        texture.SetTextureWrapT(OpenGL::GL::REPEAT);
        texture.SetMinFilter(OpenGL::GL::LINEAR);
        texture.SetMagFilter(OpenGL::GL::LINEAR);
        texture.Image2D(0, OpenGL::GL::RGBA, image.GetWidth(), image.GetHeight(), 0, OpenGL::GL::RGBA, OpenGL::GL::UNSIGNED_BYTE, image.GetData());

        context.Viewport(0, 0, 640, 480);
        context.ClearColor(Colors::blue);

        Jatta::OpenGL::Program program = LoadShader("screen.vert", "screen.frag");

        while (window.IsOpen())
        {
            Window::Update();

            context.Clear(OpenGL::GL::COLOR_BUFFER_BIT | OpenGL::GL::DEPTH_BUFFER_BIT);

            //shaderOld.Begin();
            //shaderOld.SetMatrix("orthoMatrix", Matrix::MakeOrtho(0, 0, 1, 1));
            //shaderOld.SetMatrix("modelMatrix", Matrix::identity);
            //shaderOld.SetTexture("texture", texture);
            //mesh.Draw();
            //vertexArray.Bind();
            //vertexArray.DrawArrays(OpenGL::QUADS, 0, 4);
            //vertexArray.Unbind();
            //shaderOld.End();

            /*vertexArray.Bind();
            vertexArray.DrawArrays(OpenGL::QUADS, 0, 1);
            vertexArray.Unbind();

            mesh.Draw();*/

            program.Bind();
            program.UniformMatrix4f(program.GetUniformLocation("orthoMatrix"), false, Matrix::MakeOrtho(0, 0, 1, 1));
            program.UniformMatrix4f(program.GetUniformLocation("modelMatrix"), false, Matrix::identity);
            program.Uniform1i(program.GetUniformLocation("texture"), 0);
            //shaderOld.SetTexture("texture", texture);
            texture.Active(0);
            texture.Bind();
            vertexArray.Bind();
            vertexArray.DrawArrays(OpenGL::GL::QUADS, 0, 4);
            vertexArray.Unbind();
            program.Unbind();

            context.SwapBuffers();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
