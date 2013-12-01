#include <CGUL.hpp>
using namespace CGUL;

#include <GL/glew.h>

#include <iostream>

UInt LoadShader(const String& vertexFile, const String& fragmentFile)
{
    // Create the shaders
    UInt vertexShader, fragmentShader;
    vertexShader = GL::CreateShader(GL_VERTEX_SHADER);
    fragmentShader = GL::CreateShader(GL_FRAGMENT_SHADER);

    // Load the contents of the files
    String vertexSource, fragmentSource;
    File::ReadText(vertexFile, &vertexSource);
    File::ReadText(fragmentFile, &fragmentSource);

    // Set the shader sources
    GL::ShaderSource(vertexShader, vertexSource);
    GL::ShaderSource(fragmentShader, fragmentSource);

    // Compile the shaders
    GL::CompileShader(vertexShader);
    GL::CompileShader(fragmentShader);

    // Check if shaders compiled
    SInt status;
    GL::GetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        String log;
        GL::GetShaderInfoLog(vertexShader, &log);
        throw FatalException(U8("Failed to compile shader:\n") + log);
    }
    GL::GetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        String log;
        GL::GetShaderInfoLog(fragmentShader, &log);
        throw FatalException(U8("Failed to compile shader:\n") + log);
    }

    // Create the program
    UInt program = GL::CreateProgram();

    // Setup the attributes
    GL::BindAttribLocation(program, GL::POSITION1, "vertPosition");
    GL::BindAttribLocation(program, GL::TEXCOORD1, "vertTexCoord");

    // Link the program
    GL::AttachShader(program, vertexShader);
    GL::AttachShader(program, fragmentShader);
    GL::LinkProgram(program);
    GL::GetProgramiv(program, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        String log;
        GL::GetProgramInfoLog(program, &log);
        throw FatalException(U8("Failed to link program:\n") + log);
    }
    GL::ValidateProgram(program);
    GL::GetProgramiv(program, GL_VALIDATE_STATUS, &status);
    if (status != GL_TRUE)
    {
        String log;
        GL::GetProgramInfoLog(program, &log);
        throw FatalException(U8("Failed to validate program:\n") + log);
    }

    return program;
}

UInt MakeBox()
{
    // Setup the buffer data
    Vector2 boxPositions[] = { Vector2(0, 0), Vector2(0, 1), Vector2(1, 1), Vector2(1, 0) };
    Vector2 boxTexCoords[] = { Vector2(0, 0), Vector2(0, 1), Vector2(1, 1), Vector2(1, 0) };

    // Create the vertex array object
    UInt vertexArray;
    GL::GenVertexArrays(1, &vertexArray);
    GL::BindVertexArray(vertexArray);

    // Setup the position buffer and attach it to the vertex array
    UInt buffer1;
    GL::GenBuffers(1, &buffer1);
    GL::BindBuffer(GL_ARRAY_BUFFER, buffer1);
    GL::BufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vector2), boxPositions, GL_STATIC_DRAW);
    GL::VertexAttribPointer(GL::POSITION1, 2, GL_FLOAT, false, 0, 0);
    GL::EnableVertexAttribArray(GL::POSITION1);

    // Setup the texcoord buffer and attach it to the vertex array
    UInt buffer2;
    GL::GenBuffers(1, &buffer2);
    GL::BindBuffer(GL_ARRAY_BUFFER, buffer2);
    GL::BufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vector2), boxTexCoords, GL_STATIC_DRAW);
    GL::VertexAttribPointer(GL::TEXCOORD1, 2, GL_FLOAT, false, 0, 0);
    GL::EnableVertexAttribArray(GL::TEXCOORD1);

    // All done
    GL::BindVertexArray(0);
    return vertexArray;
}

int main()
{
    try
    {
        std::cout << "Suported file formats (Reading): " << std::endl;
        CGUL::Vector<ImageLoader*> loaders = CGUL::ImageHandler::GetInstance()->GetAllLoaders();
        for (UInt32 i = 0; i < loaders.size(); i++)
        {
            std::cout << (i+1) << ". " << loaders[i]->GetName() << " (" << loaders[i]->GetExtension() << ")" << std::endl;
        }

        Image* image = new Image();
        if (!image->CanLoad("resources/logo.png"))
        {
            throw FatalException("Cannot load PNG images.");
        }

        image->Load("resources/logo.png");

        WindowStyle style;
        style.title = U8("logo.png (") + image->GetWidth() + U8(", ") + image->GetHeight() + U8(")");
        style.size = UCoord32(image->GetWidth(), image->GetHeight());
        style.backgroundColor = Colors::black;
        style.resizable = false;

        Window window;
        window.Create(style);

        OpenGL::Context context;
        context.Create(&window);

        GL::BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        GL::Enable(GL_BLEND);
        GL::Enable(GL_ALPHA_TEST);
        GL::Enable(GL_TEXTURE_2D);

        UInt program = LoadShader(U8("resources/shader.vert"), U8("resources/shader.frag"));

        UInt box = MakeBox();

        UInt texture;
        GL::GenTextures(1, &texture);
        GL::BindTexture(GL_TEXTURE_2D, texture);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        GL::TexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        GL::PixelStorei(GL_UNPACK_ALIGNMENT, 1);
        GL::TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->GetWidth(), image->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->GetData());
        GL::BindTexture(GL_TEXTURE_2D, 0);

        Timer timer;
        Float32 hue = 0.0f;
        while (window.IsOpen())
        {
            Timer::Sleep(1);
            hue = Math::Mod(hue + timer.GetDeltaTime() * 45, 360.0f);
            context.ClearColor(Color::MakeHSL(hue, 40, 255));

            context.Viewport(0, 0, window.GetWidth(), window.GetHeight());
            context.Clear(GL::COLOR_BUFFER_BIT | GL::DEPTH_BUFFER_BIT);
            GL::UseProgram(program);
            GL::UniformMatrix4fv(GL::GetUniformLocation(program, "orthoMatrix"), 1, false, Matrix::MakeOrtho2D(0, 1, 1, 0).GetData());
            GL::UniformMatrix4fv(GL::GetUniformLocation(program, "modelMatrix"), 1, false, Matrix::Identity().GetData());
            GL::Uniform1i(GL::GetUniformLocation(program, "texture"), 0);
            GL::ActiveTexture(GL_TEXTURE0);
            GL::BindTexture(GL_TEXTURE_2D, texture);
            GL::BindVertexArray(box);
            GL::DrawArrays(GL_QUADS, 0, 4);
            GL::BindVertexArray(0);
            GL::UseProgram(0);
            context.SwapBuffers();

            Window::Update();
        }
    }
    catch (Exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::hex << "Error code: 0x" << e.unique << std::dec << " (decimal " << e.unique << ")" << std::endl;
    }
}
