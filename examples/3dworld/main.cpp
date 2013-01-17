#include <Jatta.h>
#include <iostream>
using namespace Jatta;

int main()
{
    try
    {
        //Assimp::Test::DoStuff();
        Assimp::Scene test;
        test.Import("chair.DAE", Assimp::PROCESS_CALC_TANGENT_SPACE | Assimp::PROCESS_TRIANGULATE | Assimp::PROCESS_JOIN_IDENTICAL_VERTICES | Assimp::PROCESS_SORT_BY_PTYPE);

        OpenGL::Test();

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
        vertexShader.Create(OpenGL::GL::VERTEX_SHADER);
        fragmentShader.Create(OpenGL::GL::FRAGMENT_SHADER);

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
        if (!vertexShader.GetCompileStatus())
        {
            std::cout << "Failed to compile vertex." << std::endl;
            std::cout << vertexShader.GetInfoLog() << std::endl;
            return 0;
        }
        fragmentShader.Compile();
        if (!fragmentShader.GetCompileStatus())
        {
            std::cout << "Failed to compile fragment." << std::endl;
            std::cout << fragmentShader.GetInfoLog() << std::endl;
            return 0;
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
            std::cout << "Failed to link program:" << std::endl;
            std::cout << program.GetInfoLog() << std::endl;
            return 0;
        }

        program.Validate();
        if (!program.GetValidateStatus())
        {
            std::cout << "Failed to validate program:" << std::endl;
            std::cout << program.GetInfoLog() << std::endl;
            //return 0;
        }

        Shader shaderOld;
        shaderOld.Load("screen.vert", "screen.frag");
        shaderOld.BindAttribute(Graphics::position1, "vertPosition");
        shaderOld.BindAttribute(Graphics::texCoord1, "vertTexCoord");

        Float2 boxPositions[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };
        Float2 boxTexCoords[] = { Float2(0, 0), Float2(0, 1), Float2(1, 1), Float2(1, 0) };
        SubMesh mesh;
        mesh.Setup(SubMesh::Type::QUADS, 4);
        mesh.AddBuffer(boxPositions, Graphics::position1);
        mesh.AddBuffer(boxTexCoords, Graphics::texCoord1);

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
