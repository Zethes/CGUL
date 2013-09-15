#include <Jatta.h>
using namespace Jatta;

//#include <GL/glew.h>

#include <iostream>

OpenGL::Program LoadShader(const String& vertexFile, const String& fragmentFile)
{
    // Create autoreleased shaders to comply with RAII
    // If an exception occurs, the shaders' Delete methods will be called
    AutoRelease<OpenGL::Shader> vertexShader, fragmentShader;
    vertexShader.SetRelease(&OpenGL::Shader::Delete);
    fragmentShader.SetRelease(&OpenGL::Shader::Delete);

    // Create the shaders
    vertexShader.Create(GL::VERTEX_SHADER);
    fragmentShader.Create(GL::FRAGMENT_SHADER);

    // Load the contents of the files
    String vertexSource, fragmentSource;
    File::ReadText(vertexFile, &vertexSource);
    vertexShader.SetSource(vertexSource);
    File::ReadText(fragmentFile, &fragmentSource);
    fragmentShader.SetSource(fragmentSource);

    // Compile the shaders
    vertexShader.Compile();
    fragmentShader.Compile();

    // Create the program
    AutoRelease<OpenGL::Program> program;
    program.SetRelease(&OpenGL::Program::Delete);
    program.Create();

    // Setup the attributes
    program.BindAttribLocation(GL::POSITION1, "vertPosition");
    program.BindAttribLocation(GL::TEXCOORD1, "vertTexCoord");

    // Link the program
    program.AttachShader(vertexShader);
    program.AttachShader(fragmentShader);
    program.Link();
    program.Validate();

    // Do not autodelete the program once AutoRelease goes out of scope since we will be passing it
    // off in the return
    program.SetRelease(NULL);

    // All done, the shaders can be deleted (and they will automatically since they are
    // AutoRelease'd), all we care about is the program
    return program;
}

OpenGL::VertexArray MakeBox()
{
    // Setup the buffer data
    Vector2 boxPositions[] = { Vector2(0, 0), Vector2(0, 1), Vector2(1, 1), Vector2(1, 0) };
    Vector2 boxTexCoords[] = { Vector2(0, 0), Vector2(0, 1), Vector2(1, 1), Vector2(1, 0) };

    // Create the vertex array object
    AutoRelease<OpenGL::VertexArray> vertexArray;
    vertexArray.SetRelease(&OpenGL::VertexArray::Delete);
    vertexArray.Create();
    vertexArray.Bind();

    // Setup the position buffer and attach it to the vertex array
    AutoRelease<OpenGL::Buffer> buffer1;
    buffer1.SetRelease(&OpenGL::Buffer::Delete);
    buffer1.Create(GL::ARRAY_BUFFER);
    buffer1.Bind();
    buffer1.Data(4 * sizeof(Vector2), boxPositions, GL::STATIC_DRAW);
    vertexArray.AttribPointer(GL::POSITION1, 2, GL::FLOAT, false, 0, 0);
    vertexArray.EnableAttribArray(GL::POSITION1);

    // Setup the texcoord buffer and attach it to the vertex array
    AutoRelease<OpenGL::Buffer> buffer2;
    buffer2.SetRelease(&OpenGL::Buffer::Delete);
    buffer2.Create(GL::ARRAY_BUFFER);
    buffer2.Bind();
    buffer2.Data(4 * sizeof(Vector2), boxTexCoords, GL::STATIC_DRAW);
    vertexArray.AttribPointer(GL::TEXCOORD1, 2, GL::FLOAT, false, 0, 0);
    vertexArray.EnableAttribArray(GL::TEXCOORD1);

    // All done
    vertexArray.Unbind();
    vertexArray.SetRelease(NULL);
    return vertexArray;
}

int main()
{
    try
    {
        ImageLoaders::BMP bmpLoader("resources/logo.bmp");
        if (!bmpLoader.CanLoad())
            throw FatalException("Cannot load BMP images.");

        Image*image = bmpLoader.Load();
        std::cout << "Image has been loaded!" << std::endl;

        WindowStyle style;
        style.title = U8("logo.bmp (") + image->GetWidth() + U8(", ") + image->GetHeight() + U8(")");
        style.width = image->GetWidth();
        style.height = image->GetHeight();
        style.backgroundColor = Colors::black;
        style.resizable = false;

        Window window;
        window.Create(style);

        OpenGL::Context context;
        context.Create(&window);

        Jatta::OpenGL::BlendFunc(Jatta::GL::SRC_ALPHA, Jatta::GL::ONE_MINUS_SRC_ALPHA);
        Jatta::OpenGL::Enable(Jatta::GL::BLEND);
        //Jatta::OpenGL::Enable(Jatta::GL::ALPHA_TEST); (Missing this constant)
        Jatta::OpenGL::Enable(Jatta::GL::TEXTURE_2D);

        OpenGL::Program program = LoadShader(U8("resources/shader.vert"), U8("resources/shader.frag"));

        OpenGL::VertexArray box = MakeBox();

        OpenGL::Texture texture;
        texture.Create(GL::TEXTURE_2D);
        texture.Bind();
        texture.SetTextureWrapS(GL::REPEAT);
        texture.SetTextureWrapT(GL::REPEAT);
        texture.SetMinFilter(GL::LINEAR);
        texture.SetMagFilter(GL::LINEAR);
        texture.Image2D(0, GL::RGBA, image->GetWidth(), image->GetHeight(), 0, image->GetFormat().GLFormat, GL::UNSIGNED_BYTE, (void*)image->GetData());
        texture.Unbind();

        Timer timer;
        Float32 hue = 0.0f;
        while (window.IsOpen())
        {
            Timer::Sleep(1);
            hue = Math::Mod(hue + timer.GetDeltaTime() * 45, 360.0f);
            context.ClearColor(Color::MakeHSL(hue, 40, 255));

            context.Viewport(0, 0, window.GetWidth(), window.GetHeight());
            context.Clear(GL::COLOR_BUFFER_BIT | GL::DEPTH_BUFFER_BIT);
            program.Bind();
            OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("orthoMatrix"), false, Matrix::MakeOrtho(0, 1, 1, 0));
            OpenGL::Program::UniformMatrix4f(program.GetUniformLocation("modelMatrix"), false, Matrix::Identity());
            OpenGL::Program::Uniform1i(program.GetUniformLocation("texture"), 0);
            OpenGL::ClearErrors();
            OpenGL::Texture::Active(0);
            texture.Bind();
            box.Bind();
            box.DrawArrays(GL::QUADS, 0, 4);
            box.Unbind();
            program.Unbind();
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
