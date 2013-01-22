#include "Object.h"
using namespace Jatta;

Object::Object()
{
    position = Float3(0);
    orientation = Float3(0);
}

void Object::Draw() const
{
    
}

void Object::SetPosition(const Float3& position)
{
}

Float3 Object::GetPosition() const
{
}

void Object::SetOrientation(const Float3& orientation)
{
}

void Object::GetOrientation() const
{
}

void Object::LoadMesh(const String& filename)
{
}