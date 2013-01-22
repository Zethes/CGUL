#pragma once
#include <Jatta.h>

class Object
{
    Jatta::Float3 position;
    Jatta::Float3 orientation;

    std::vector<Jatta::OpenGL::VertexArray> meshes;
    std::vector<Jatta::OpenGL::Texture> textures;
public:
    Object();

    void Draw() const;

    void SetPosition(const Jatta::Float3& position);
    Jatta::Float3 GetPosition() const;
    void SetOrientation(const Jatta::Float3& orientation);
    void GetOrientation() const;

    void LoadMesh(const Jatta::String& filename);
};