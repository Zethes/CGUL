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
    if (!Jatta::File::ReadText(vertexFile, &vertexSource))
    {
        std::ostringstream ss;
        ss << "Failed to load vertex shader \"" << vertexFile << "\"!";
        throw std::runtime_error(ss.str().c_str());
    }
    vertexShader.Source(vertexSource);
    if (!Jatta::File::ReadText(fragmentFile, &fragmentSource))
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
OpenGL::VertexArray MakeBox(Float2 size)
{
    // Setup the buffer data
    Float2 boxPositions[] = { Float2(0, 0), Float2(0, size.y), Float2(size.x, size.y), Float2(size.x, 0) };
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
    Jatta::Matrix wee;
    wee[1][2] = 5;
    std::cout << wee << std::endl;
    try
    {
        // Setup the window
        WindowStyle style;
        style.title = "A Quick Brown Fox Jumps Over The Lazy Dog";
        style.width = 800;
        style.height = 350;
        style.backgroundColor = Colors::black;
        style.resizable = false;
        Window window;
        window.Create(style);

        // Create the OpenGL context
        OpenGL::Context context;
        context.Create(&window);

        OpenGL::Program program = LoadShader("Resources/screen.vert", "Resources/screen.frag");

        Font font;
        if (font.Load("Resources/Arial.ttf") == -1)
        { throw std::runtime_error("Failed to load 'Resources/Arial.ttf'."); }
        if (font.Load("Resources/epgyosho.ttf") == -1)
        { throw std::runtime_error("Failed to load 'Resources/epgyosho.ttf'."); }
        if (font.Load("Resources/LastResort.ttf") == -1)
        { throw std::runtime_error("Failed to load 'Resources/LastResort.ttf'."); }

        Image image[22];
        OpenGL::Texture texture[22];
        OpenGL::VertexArray box[22];

        for (unsigned int i = 7; i < 27; ++i)
        {
            font.SetSize(i);
            image[i-7] = font.GenerateText(Jatta::Colors::white,"A Quick Brown Fox Jumps Over The Lazy Dog 0123456789");

            texture[i-7].Create(OpenGL::GL::TEXTURE_2D);
            texture[i-7].Bind();
            texture[i-7].SetTextureWrapS(OpenGL::GL::REPEAT);
            texture[i-7].SetTextureWrapT(OpenGL::GL::REPEAT);
            texture[i-7].SetMinFilter(OpenGL::GL::LINEAR);
            texture[i-7].SetMagFilter(OpenGL::GL::LINEAR);
            texture[i-7].Image2D(0, OpenGL::GL::RGBA, image[i-7].GetWidth(), image[i-7].GetHeight(), 0, OpenGL::GL::RGBA, OpenGL::GL::UNSIGNED_BYTE, image[i-7].GetData());
            texture[i-7].Unbind();

            box[i-7] = MakeBox(Float2(image[i-7].GetWidth(), image[i-7].GetHeight()));
        }

        font.SetSize(16);
        image[21] = font.GenerateText(Jatta::Colors::white,"こんにちわ");//"こ\nん\nに\nち\nわ");

        texture[21].Create(OpenGL::GL::TEXTURE_2D);
        texture[21].Bind();
        texture[21].SetTextureWrapS(OpenGL::GL::REPEAT);
        texture[21].SetTextureWrapT(OpenGL::GL::REPEAT);
        texture[21].SetMinFilter(OpenGL::GL::LINEAR);
        texture[21].SetMagFilter(OpenGL::GL::LINEAR);
        texture[21].Image2D(0, OpenGL::GL::RGBA, image[21].GetWidth(), image[21].GetHeight(), 0, OpenGL::GL::RGBA, OpenGL::GL::UNSIGNED_BYTE, image[21].GetData());
        texture[21].Unbind();

        box[21] = MakeBox(Float2(image[21].GetWidth(), image[21].GetHeight()));

        while (window.IsOpen())
        {
            Window::Update();

            context.Viewport(0, 0, window.GetWidth(), window.GetHeight());
            context.Clear(OpenGL::GL::COLOR_BUFFER_BIT | OpenGL::GL::DEPTH_BUFFER_BIT);

            UInt32 y = 0;

            program.Bind();
            OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("orthoMatrix"), false, Matrix::MakeOrtho(0, window.GetWidth(), window.GetHeight(), 0));
            for (unsigned int i = 7; i < 27; ++i)
            {
                OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("modelMatrix"), false, Matrix::MakeTranslation(Float2(0,y)));
                OpenGL::Program::Uniform1i(program.GetUniformLocation("texture"), texture[i-7].GetID());
                OpenGL::ClearErrors();
                OpenGL::Texture::Active(texture[i-7].GetID());
                texture[i-7].Bind();
                box[i-7].Bind();
                box[i-7].DrawArrays(OpenGL::GL::QUADS, 0, 4);
                box[i-7].Unbind();
                y += image[i-7].GetHeight();
            }

            OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("modelMatrix"), false, Matrix::MakeTranslation(Float2(800-image[21].GetWidth(),0)));
            OpenGL::Program::Uniform1i(program.GetUniformLocation("texture"), texture[21].GetID());
            OpenGL::ClearErrors();
            OpenGL::Texture::Active(texture[21].GetID());
            texture[21].Bind();
            box[21].Bind();
            box[21].DrawArrays(OpenGL::GL::QUADS, 0, 4);
            box[21].Unbind();

            program.Unbind();

            context.SwapBuffers();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
