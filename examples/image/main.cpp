#include <iostream>
#include <sstream>
#include <Jatta.h>
using namespace Jatta;

/** @brief Loads a shader from a vertex file and a fragment file.
 *  @param vertexFile The file name of the vertex shader.
 *  @param fragmentFile The file name of the fragment shader.
 *  @return The compile program.
 */
Jatta::OpenGL::Program LoadShader(const String& vertexFile, const String& fragmentFile)
{
    // Create the shaders
    OpenGL::Shader vertexShader, fragmentShader;
    vertexShader.Create(Jatta::OpenGL::GL::VERTEX_SHADER);
    fragmentShader.Create(Jatta::OpenGL::GL::FRAGMENT_SHADER);

    // Load the contents of the files
    String vertexSource, fragmentSource;
    if (!Jatta::File::GetText(vertexFile, &vertexSource))
    {
        std::ostringstream ss;
        ss << "Failed to load vertex shader \"" << vertexFile << "\"!";
        throw std::runtime_error(ss.str().c_str());
    }
    vertexShader.Source(vertexSource);
    if (!Jatta::File::GetText(fragmentFile, &fragmentSource))
    {
        std::ostringstream ss;
        ss << "Failed to load fragment shader \"" << fragmentFile << "\"!";
        throw std::runtime_error(ss.str().c_str());
    }
    fragmentShader.Source(fragmentSource);

    // Compile the vertex shader
    vertexShader.Compile();
    if (!vertexShader.GetCompileStatus())
    {
        std::ostringstream ss;
        ss << "Failed to compile vertex shader \"" << vertexFile << "\":\n";
        ss << vertexShader.GetInfoLog();
        throw std::runtime_error(ss.str().c_str());
    }

    // Compile the vertex shader
    fragmentShader.Compile();
    if (!fragmentShader.GetCompileStatus())
    {
        std::ostringstream ss;
        ss << "Failed to compile fragment shader \"" << fragmentFile << "\":\n";
        ss << fragmentShader.GetInfoLog();
        throw std::runtime_error(ss.str().c_str());
    }

    // Create the program
    OpenGL::Program program;
    program.Create();

    // Setup the attributes
    program.BindAttribLocation(OpenGL::POSITION1, "vertPosition");
    program.BindAttribLocation(OpenGL::TEXCOORD1, "vertTexCoord");

    // Link the program
    program.AttachShader(vertexShader);
    program.AttachShader(fragmentShader);
    program.Link();
    if (!program.GetLinkStatus())
    {
        std::ostringstream ss;
        ss << "Failed to link program (vert: \"" << vertexFile << "\", frag: \"" << fragmentFile << "\"):\n";
        ss << program.GetInfoLog();
        throw std::runtime_error(ss.str().c_str());
    }
    program.Validate();
    if (!program.GetValidateStatus())
    {
        std::ostringstream ss;
        ss << "Failed to validate program (vert: \"" << vertexFile << "\", frag: \"" << fragmentFile << "\"):\n";
        ss << program.GetInfoLog();
        throw std::runtime_error(ss.str().c_str());
    }
    return program;
}

/** @brief Creates a 2D box with coordinates from (0, 0) to (1, 1).
 *  @return The vertex array object.
 */
OpenGL::VertexArray MakeBox()
{
    // Setup the buffer data
    Float2 boxPositions[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };
    Float2 boxTexCoords[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };

    // Create the vertex array object
    OpenGL::VertexArray vertexArray;
    vertexArray.Create();
    vertexArray.Bind();

    // Setup the position buffer and attach it to the vertex array
    OpenGL::Buffer buffer1;
    buffer1.Create(OpenGL::GL::ARRAY_BUFFER);
    buffer1.Bind();
    buffer1.Data(4 * sizeof(Float2), boxPositions, OpenGL::GL::STATIC_DRAW);
    vertexArray.AttribPointer(OpenGL::POSITION1, 2, OpenGL::GL::FLOAT, false, 0, 0);
    vertexArray.EnableAttribArray(OpenGL::POSITION1);

    // Setup the texcoord buffer and attach it to the vertex array
    OpenGL::Buffer buffer2;
    buffer2.Create(OpenGL::GL::ARRAY_BUFFER);
    buffer2.Bind();
    buffer2.Data(4 * sizeof(Float2), boxTexCoords, OpenGL::GL::STATIC_DRAW);
    vertexArray.AttribPointer(OpenGL::TEXCOORD1, 2, OpenGL::GL::FLOAT, false, 0, 0);
    vertexArray.EnableAttribArray(OpenGL::TEXCOORD1);

    // All done
    vertexArray.Unbind();
    return vertexArray;
}

int main()
{
    try
    {
        // Setup the window
        WindowStyle style;
        style.title = "Jatta Window";
        style.width = 640;
        style.height = 480;
        style.backgroundColor = Colors::black;
        style.resizable = false;
        Window window;
        window.Create(style);

        // Create the OpenGL context
        OpenGL::Context context;
        context.Create(&window);

        OpenGL::Program program = LoadShader("Resources/screen.vert", "Resources/screen.frag");

        Image image;
        image.LoadPng("Resources/sky.png");

        OpenGL::Texture texture;
        texture.Create(OpenGL::GL::TEXTURE_2D);
        texture.Bind();
        texture.SetTextureWrapS(OpenGL::GL::REPEAT);
        texture.SetTextureWrapT(OpenGL::GL::REPEAT);
        texture.SetMinFilter(OpenGL::GL::LINEAR);
        texture.SetMagFilter(OpenGL::GL::LINEAR);
        texture.Image2D(0, OpenGL::GL::RGBA, image.GetWidth(), image.GetHeight(), 0, OpenGL::GL::RGBA, OpenGL::GL::UNSIGNED_BYTE, image.GetData());
        texture.Unbind();

        OpenGL::VertexArray box = MakeBox();

        context.Viewport(0, 0, 640, 480);
    
        context.ClearColor(Colors::red);

        while (window.IsOpen())
        {
            Window::Update();

            context.Clear(OpenGL::GL::COLOR_BUFFER_BIT);

            program.Bind();
            OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("orthoMatrix"), false, Matrix::MakeOrtho(0, 1, 1, 0));
            OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("modelMatrix"), false, Matrix::identity);
            OpenGL::Program::Uniform1i(program.GetUniformLocation("texture"), 0);
            OpenGL::ClearErrors();
            OpenGL::Texture::Active(0);
            texture.Bind();
            box.Bind();
            box.DrawArrays(OpenGL::GL::QUADS, 0, 4);
            box.Unbind();
            program.Unbind();

            context.SwapBuffers();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
