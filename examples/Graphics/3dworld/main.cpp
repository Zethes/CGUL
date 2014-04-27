#include <CGUL.hpp>
using namespace CGUL;

#include <GL/glew.h>

#include <iostream>

UIntN LoadShader(const String& vertexFile, const String& fragmentFile)
{
    // Create the shaders
    UIntN vertexShader, fragmentShader;
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
    SIntN status;
    GL::GetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        CGUL::String log;
        GL::GetShaderInfoLog(vertexShader, &log);
        throw FatalException(U8("Failed to compile shader:\n") + log);
    }
    GL::GetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        CGUL::String log;
        GL::GetShaderInfoLog(fragmentShader, &log);
        throw FatalException(U8("Failed to compile shader:\n") + log);
    }

    // Create the program
    UIntN program = GL::CreateProgram();

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
        CGUL::String log;
        GL::GetProgramInfoLog(program, &log);
        throw FatalException(U8("Failed to link program:\n") + log);
    }
    GL::ValidateProgram(program);
    GL::GetProgramiv(program, GL_VALIDATE_STATUS, &status);
    if (status != GL_TRUE)
    {
        CGUL::String log;
        GL::GetProgramInfoLog(program, &log);
        throw FatalException(U8("Failed to validate program:\n") + log);
    }

    return program;
}

UIntN MakeBox()
{
    // Setup the buffer data
    Vector3F boxPositions[] = {Vector3F(-0.5f, -0.5f, -0.5f), Vector3F(-0.5f,  0.5f, -0.5f), Vector3F( 0.5f,  0.5f, -0.5f), Vector3F( 0.5f, -0.5f, -0.5f),
                               Vector3F( 0.5f, -0.5f,  0.5f), Vector3F( 0.5f,  0.5f,  0.5f), Vector3F(-0.5f,  0.5f,  0.5f), Vector3F(-0.5f, -0.5f,  0.5f),
                               Vector3F(-0.5f, -0.5f,  0.5f), Vector3F(-0.5f,  0.5f,  0.5f), Vector3F(-0.5f,  0.5f, -0.5f), Vector3F(-0.5f, -0.5f, -0.5f),
                               Vector3F( 0.5f, -0.5f, -0.5f), Vector3F( 0.5f,  0.5f, -0.5f), Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 0.5f, -0.5f,  0.5f),
                               Vector3F(-0.5f, -0.5f, -0.5f), Vector3F( 0.5f, -0.5f, -0.5f), Vector3F( 0.5f, -0.5f,  0.5f), Vector3F(-0.5f, -0.5f,  0.5f),
                               Vector3F(-0.5f,  0.5f, -0.5f), Vector3F(-0.5f,  0.5f,  0.5f), Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 0.5f,  0.5f, -0.5f)};

    Vector2F boxTexCoords[] = {Vector2F(0.0f, 0.0f), Vector2F(0.0f, 1.0f), Vector2F(1.0f, 1.0f), Vector2F(1.0f, 0.0f),
                               Vector2F(0.0f, 0.0f), Vector2F(0.0f, 1.0f), Vector2F(1.0f, 1.0f), Vector2F(1.0f, 0.0f),
                               Vector2F(0.0f, 0.0f), Vector2F(0.0f, 1.0f), Vector2F(1.0f, 1.0f), Vector2F(1.0f, 0.0f),
                               Vector2F(0.0f, 0.0f), Vector2F(0.0f, 1.0f), Vector2F(1.0f, 1.0f), Vector2F(1.0f, 0.0f),
                               Vector2F(0.5f, 0.5f), Vector2F(0.5f, 0.5f), Vector2F(0.5f, 0.5f), Vector2F(0.5f, 0.5f),
                               Vector2F(0.5f, 0.5f), Vector2F(0.5f, 0.5f), Vector2F(0.5f, 0.5f), Vector2F(0.5f, 0.5f)};

    // Create the vertex array object
    UIntN vertexArray;
    GL::GenVertexArrays(1, &vertexArray);
    GL::BindVertexArray(vertexArray);

    // Setup the position buffer and attach it to the vertex array
    UIntN buffer1;
    GL::GenBuffers(1, &buffer1);
    GL::BindBuffer(GL_ARRAY_BUFFER, buffer1);
    GL::BufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vector3F), boxPositions, GL_STATIC_DRAW);
    GL::VertexAttribPointer(GL::POSITION1, 3, GL_FLOAT, false, 0, 0);
    GL::EnableVertexAttribArray(GL::POSITION1);

    // Setup the texcoord buffer and attach it to the vertex array
    UIntN buffer2;
    GL::GenBuffers(1, &buffer2);
    GL::BindBuffer(GL_ARRAY_BUFFER, buffer2);
    GL::BufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vector2F), boxTexCoords, GL_STATIC_DRAW);
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
        Image image;
        image.Load("resources/jattabox.png");

        WindowStyle style;
        style.title = U8("CGUL - 3D World");
        style.size = UCoord32(640, 480);
        style.backgroundColor = Colors::black;
        style.resizable = true;

        Window window;
        window.Create(style);

        OpenGL::Context context;
        context.Create(&window);

        GL::BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        GL::Enable(GL_BLEND);
        GL::Enable(GL_ALPHA_TEST);
        GL::Enable(GL_TEXTURE_2D);
        GL::Enable(GL_DEPTH_TEST);
        GL::Enable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        UIntN program = LoadShader(U8("resources/shader.vert"), U8("resources/shader.frag"));

        UIntN box = MakeBox();

        UIntN texture;
        GL::GenTextures(1, &texture);
        GL::BindTexture(GL_TEXTURE_2D, texture);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        GL::TexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        GL::PixelStorei(GL_UNPACK_ALIGNMENT, 1);
        GL::TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetData< void >());
        GL::BindTexture(GL_TEXTURE_2D, 0);

        Timer timer;
        Float32 hue = 0.0f;
        while (window.IsOpen())
        {
            Float32 deltaTime = timer.GetDeltaTime();
            Timer::Sleep(1);
            hue = Math::Mod(hue + deltaTime * 0.125f, 1.0f);
            context.ClearColor(Color::MakeHSV(hue, 0.156862745098039f, 1.0f));

            Float32 movement = 1 + Math::Cos(hue / 10.0f);
            static Float32 rot = 0;
            rot += deltaTime / 1.0f;

            context.Viewport(0, 0, window.GetWidth(), window.GetHeight());
            context.Clear(GL::COLOR_BUFFER_BIT | GL::DEPTH_BUFFER_BIT);
            GL::UseProgram(program);
            //GL::UniformMatrix4fv(GL::GetUniformLocation(program, "orthoMatrix"), 1, false, Matrix::MakeOrtho2D(0, 1280, 768, 0).GetData());
            MatrixF view = MatrixF::MakeLookAt(Vector3F(Math::Cos(rot) * 50, Math::Cos(rot) * 50, Math::Sin(rot) * 50), Vector3F(0, 0, 0), Vector3F(0, -1, 0));
            MatrixF projection = MatrixF::MakePerspective(45.0, window.GetWidth() / (Float32)window.GetHeight(), 1, 1000);
            MatrixF vp = view * projection;

            MatrixF model;
            model = MatrixF::MakeScaling(Vector3F(20, 20, 20)) * model;

            //Matrix wvp = model * Matrix::MakeOrtho2D(0, 1280, 768, 0);
            MatrixF wvp = model * vp;
            GL::UniformMatrix4fv(GL::GetUniformLocation(program, "matrix"), 1, false, wvp.GetData());
            GL::Uniform1i(GL::GetUniformLocation(program, "texture"), 0);
            GL::ActiveTexture(GL_TEXTURE0);
            GL::BindTexture(GL_TEXTURE_2D, texture);
            GL::BindVertexArray(box);
            GL::DrawArrays(GL_QUADS, 0, 24);
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
