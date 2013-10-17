#include <Jatta.h>
using namespace Jatta;

#include <GL/glew.h>

#include <iostream>

UInt LoadShader(const String& vertexFile, const String& fragmentFile)
{
    // Create autoreleased shaders to comply with RAII
    // If an exception occurs, the shaders' Delete methods will be called
    UInt vertexShader, fragmentShader;

    // Create the shaders
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Load the contents of the files
    String vertexSource, fragmentSource;
    File::ReadText(vertexFile, &vertexSource);
    File::ReadText(fragmentFile, &fragmentSource);

    // Set the shader sources
    const char* characters = vertexSource.GetCString();
    const GLchar** data = &characters;
    GLint count = (GLint)vertexSource.GetSize();
    glShaderSource((GLuint)vertexShader, (GLsizei)1, data, &count);
    characters = fragmentSource.GetCString();
    count = (GLint)fragmentSource.GetSize();
    glShaderSource((GLuint)fragmentShader, (GLsizei)1, data, &count);

    // Compile the shaders
    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    // Create the program
    UInt program = glCreateProgram();

    // Setup the attributes
    glBindAttribLocation(program, GL::POSITION1, "vertPosition");
    glBindAttribLocation(program, GL::TEXCOORD1, "vertTexCoord");

    // Link the program
    SInt status;
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    // todo: check status, error
    glValidateProgram(program);
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    // todo: check status, error

    // All done, the shaders can be deleted (and they will automatically since they are
    // AutoRelease'd), all we care about is the program
    return program;
}

UInt MakeBox()
{
    // Setup the buffer data
    Vector2 boxPositions[] = { Vector2(0, 0), Vector2(0, 1), Vector2(1, 1), Vector2(1, 0) };
    Vector2 boxTexCoords[] = { Vector2(0, 0), Vector2(0, 1), Vector2(1, 1), Vector2(1, 0) };

    // Create the vertex array object
#   ifndef MACOS
    UInt vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
#   else
    UInt vertexArray;
    glGenVertexArraysAPPLE(1, &vertexArray);
    glBindVertexArrayAPPLE(vertexArray);
#   endif

    // Setup the position buffer and attach it to the vertex array
    UInt buffer1;
    glGenBuffers(1, &buffer1);
    glBindBuffer(GL_ARRAY_BUFFER, buffer1);
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vector2), boxPositions, GL_STATIC_DRAW);
    glVertexAttribPointer(GL::POSITION1, 2, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(GL::POSITION1);

    // Setup the texcoord buffer and attach it to the vertex array
    UInt buffer2;
    glGenBuffers(1, &buffer2);
    glBindBuffer(GL_ARRAY_BUFFER, buffer2);
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vector2), boxTexCoords, GL_STATIC_DRAW);
    glVertexAttribPointer(GL::TEXCOORD1, 2, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(GL::TEXCOORD1);

    // All done
#   ifndef MACOS
    glBindVertexArray(0);
#   else
    glBindVertexArrayAPPLE(0);
#   endif
    return vertexArray;
}

int main()
{
    try
    {
        ImageLoaders::PNG loader;
        if (!loader.CanLoad("resources/logo.png"))
        {
            throw FatalException("Cannot load PNG images.");
        }
        Image* image = loader.Load("resources/logo.png");

        WindowStyle style;
        style.title = U8("logo.png (") + image->GetWidth() + U8(", ") + image->GetHeight() + U8(")");
        style.width = image->GetWidth();
        style.height = image->GetHeight();
        style.backgroundColor = Colors::black;
        style.resizable = false;

        Window window;
        window.Create(style);

        OpenGL::Context context;
        context.Create(&window);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_TEXTURE_2D);

        UInt program = LoadShader(U8("resources/shader.vert"), U8("resources/shader.frag"));

        UInt box = MakeBox();

        UInt texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->GetWidth(), image->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->GetData());
        glBindTexture(GL_TEXTURE_2D, 0);

        Timer timer;
        Float32 hue = 0.0f;
        while (window.IsOpen())
        {
            Timer::Sleep(1);
            hue = Math::Mod(hue + timer.GetDeltaTime() * 45, 360.0f);
            context.ClearColor(Color::MakeHSL(hue, 40, 255));

            context.Viewport(0, 0, window.GetWidth(), window.GetHeight());
            context.Clear(GL::COLOR_BUFFER_BIT | GL::DEPTH_BUFFER_BIT);
            glUseProgram(program);
            glUniformMatrix4fv(glGetUniformLocation(program, "orthoMatrix"), 1, false, Matrix::MakeOrtho(0, 1, 1, 0).GetData());
            glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, false, Matrix::Identity().GetData());
            glUniform1i(glGetUniformLocation(program, "texture"), 0);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture);
            glBindVertexArray(box);
            glDrawArrays(GL_QUADS, 0, 4);
            glBindVertexArray(0);
            glUseProgram(0);
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
