/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Model.h"
#include "../File/File.h"
#include "../Math/Float2.h"
#include "../Math/Float3.h"
#include "../Math/Float4.h"
#include "../Graphics/Graphics.h"
#include "../Utility/String.h"
#include <string.h>

namespace
{
    struct ObjGroup
    {
        Jatta::String name;
        std::vector<Jatta::String> faces;
    };
    struct ObjData
    {
        Jatta::Float32* positions;
        Jatta::Byte positionSize;
        Jatta::UInt32 positionCount;
        Jatta::Float32* texCoords;
        Jatta::Byte texCoordSize;
        Jatta::UInt32 texCoordCount;
        Jatta::Float32* normals;
        Jatta::Byte normalSize;
        Jatta::UInt32 normalCount;
        std::vector<ObjGroup> groups;
    };
}

#include <iostream>
static Jatta::Float4 ToVector(const Jatta::String& input, Jatta::Byte* size)
{
    Jatta::Float4 data;
    std::istringstream ss;
    ss.str(input.GetData());
    for (*size = 0; *size < 4 && ss.good(); (*size)++)
    {
        ss >> data[*size];
    }
    return data; // TODO: check for errors
}

static void CreateGroup(Jatta::Group* group, std::vector<Jatta::String> data, std::vector<Jatta::Float4>& positions, Jatta::Byte positionsSize, std::vector<Jatta::Float4>& texCoords, Jatta::Byte texCoordsSize, std::vector<Jatta::Float4>& normals, Jatta::Byte normalsSize)
{
    group->vertexCount = data.size();
    if (positionsSize != 0)
    {
        float* positionData = new float[group->vertexCount * positionsSize];
        for (Jatta::UInt32 i = 0; i < positions.size(); i++)
        {
            memcpy(positionData + i * positionsSize, &positions[i], positionsSize);
        }
        Jatta::VertexBuffer buffer;
        buffer.buffer = positionData;
        buffer.index = Jatta::Graphics::position1;
        buffer.size = positionsSize;
        group->AddBuffer(buffer);
    }
    if (texCoordsSize != 0)
    {
        float* texCoordData = new float[group->vertexCount * texCoordsSize];
        for (Jatta::UInt32 i = 0; i < texCoords.size(); i++)
        {
            memcpy(texCoordData + i * texCoordsSize, &texCoords[i], texCoordsSize);
        }
        Jatta::VertexBuffer buffer;
        buffer.buffer = texCoordData;
        buffer.index = Jatta::Graphics::texCoord1;
        buffer.size = texCoordsSize;
        group->AddBuffer(buffer);
    }
    if (normalsSize != 0)
    {
        float* normalData = new float[group->vertexCount * normalsSize];
        for (Jatta::UInt32 i = 0; i < normals.size(); i++)
        {
            memcpy(normalData + i * normalsSize, &normals[i], normalsSize);
        }
        Jatta::VertexBuffer buffer;
        buffer.buffer = normalData;
        buffer.index = Jatta::Graphics::normal1;
        buffer.size = normalsSize;
        group->AddBuffer(buffer);
    }
}

static void Parse(ObjData* data, const Jatta::String& fileName)
{
    std::vector<Jatta::String> file;
    if (!Jatta::File::GetLines(fileName, &file))
    {
        return;
    }

    std::vector<Jatta::String> positionStrings;
    std::vector<Jatta::String> texCoordStrings;
    std::vector<Jatta::String> normalStrings;
    std::vector<Jatta::String> groupStrings;

    Jatta::Byte positionSize = 0;
    Jatta::Byte texCoordSize = 0;
    Jatta::Byte normalSize = 0;

    for (auto it = file.begin(); it != file.end(); it++)
    {
        it->Trim();
        std::vector<Jatta::String> explode = it->Explode(" ", 1);
        if (explode.size() < 2)
        {
            continue;
        }
        explode[1].TrimStart();
        if (explode[0] == "#")
        {
            continue;
        }
        else if (explode[0] == "v")
        {
            Jatta::UInt32 size = explode[1].Count(" ") + 1;
            if (size < 2 || size > 4)
            {
                throw std::runtime_error("Invalid OBJ. Invalid position.");
            }
            if (positionSize == 0)
            {
                positionSize = size;
            }
            else if (positionSize != size)
            {
                throw std::runtime_error("Invalid OBJ. Inconsistent position size.");
            }
            positionStrings.push_back(explode[1]);
        }
        else if (explode[0] == "vt")
        {
            Jatta::UInt32 size = explode[1].Count(" ") + 1;
            if (size < 2 || size > 3)
            {
                throw std::runtime_error("Invalid OBJ. Invalid texture coordinate.");
            }
            if (texCoordSize == 0)
            {
                texCoordSize = size;
            }
            else if (texCoordSize != size)
            {
                throw std::runtime_error("Invalid OBJ. Inconsistent texture coordinate size.");
            }
            texCoordStrings.push_back(explode[1]);
        }
        else if (explode[0] == "vn")
        {
            Jatta::UInt32 size = explode[1].Count(" ") + 1;
            if (size != 3)
            {
                throw std::runtime_error("Invalid OBJ. Invalid normal.");
            }
            if (normalSize == 0)
            {
                normalSize = size;
            }
            else if (normalSize != size)
            {
                throw std::runtime_error("Invalid OBJ. Inconsistent normal size.");
            }
            normalStrings.push_back(explode[1]);
        }
        else if (explode[0] == "g")
        {
            ObjGroup group;
            group.name = explode[1];
            data->groups.push_back(group);
        }
        else if (explode[0] == "f")
        {
            if (data->groups.empty())
            {
                ObjGroup group;
                group.name = "";
                data->groups.push_back(group);
            }
            data->groups.back().faces.push_back(explode[1]);
        }
        else if (explode[0] == "mtllib")
        {
            // TODO: .obj mtllib
        }
        else if (explode[0] == "usemtl")
        {
            // TODO: .obj usemtl
        }
        else if (explode[0] == "s")
        {
            // TODO: .obj s
        }
        else
        {
            std::ostringstream ss;
            ss << "Invalid OBJ file, found: " << explode[0];
            throw std::runtime_error(ss.str().c_str());
        }
    }

    data->positions = nullptr;
    data->texCoords = nullptr;
    data->normals = nullptr;
    if (positionSize != 0)
    {
        data->positions = new Jatta::Float32[positionStrings.size() * positionSize];
        Jatta::UInt32 index = 0;
        for (auto it = positionStrings.begin(); it != positionStrings.end(); it++)
        {
            std::vector<Jatta::String> explode = it->Explode(" ");
            for (auto j = explode.begin(); j != explode.end(); j++)
            {
                data->positions[index++] = j->To<Jatta::Float32>();
            }
        }
        data->positionSize = positionSize;
        data->positionCount = positionStrings.size();
    }
    if (texCoordSize != 0)
    {
        data->texCoords = new Jatta::Float32[texCoordStrings.size() * texCoordSize];
        Jatta::UInt32 index = 0;
        for (auto it = texCoordStrings.begin(); it != texCoordStrings.end(); it++)
        {
            std::vector<Jatta::String> explode = it->Explode(" ");
            for (auto j = explode.begin(); j != explode.end(); j++)
            {
                data->texCoords[index++] = j->To<Jatta::Float32>();
            }
        }
        data->texCoordSize = texCoordSize;
        data->texCoordCount = texCoordStrings.size();
    }
    if (normalSize != 0)
    {
        data->normals = new Jatta::Float32[normalStrings.size() * normalSize];
        Jatta::UInt32 index = 0;
        for (auto it = normalStrings.begin(); it != normalStrings.end(); it++)
        {
            std::vector<Jatta::String> explode = it->Explode(" ");
            for (auto j = explode.begin(); j != explode.end(); j++)
            {
                data->normals[index++] = j->To<Jatta::Float32>();
            }
        }
        data->normalSize = normalSize;
        data->normalCount = normalStrings.size();
    }
}

static std::vector<Jatta::Group> CreateGroups(ObjData* data)
{
    std::vector<Jatta::Group> groups;
    for (auto i = data->groups.begin(); i != data->groups.end(); i++)
    {
        Jatta::Group group;
        group.name = i->name;
        group.vertexCount = i->faces.size() * 3;
        int faceSize = 0;
        bool first = true;
        bool hasTexCoord, faceHasTexCoord;
        bool hasNormal, faceHasNormal;
        Jatta::Float32* positions = new Jatta::Float32[i->faces.size() * data->positionSize * 3];
        unsigned int positionPos = 0;
        Jatta::Float32* texCoords = new Jatta::Float32[i->faces.size() * data->texCoordSize * 3];
        unsigned int texCoordPos = 0;
        Jatta::Float32* normals = new Jatta::Float32[i->faces.size() * data->normalSize * 3];
        unsigned int normalPos = 0;
        for (auto j = i->faces.begin(); j != i->faces.end(); j++)
        {
            std::vector<Jatta::String> faces = j->Explode(" ");
            // TODO: intelligently check which buffers need to be created
            Jatta::Byte size = faces.size();
            if (size < 3 || size > 4)
            {
                throw std::runtime_error("Invalid OBJ.  Incorrect face size.");
            }
            if (faceSize == 0)
            {
                faceSize = size;
            }
            else if (faceSize != size)
            {
                throw std::runtime_error("Invalid OBJ.  Inconsistent face size.");
            }
            for (auto k = faces.begin(); k != faces.end(); k++)
            {
                std::vector<Jatta::String> faceData = k->Explode("/");
                if (!faceData[0].Is<Jatta::UInt32>())
                {
                    throw std::runtime_error("Invalid OBJ.  No position data.");
                }
                faceHasTexCoord = false;
                faceHasNormal = false;
                if (faceData.size() == 3)
                {
                    if (faceData[1].Is<Jatta::UInt32>())
                    {
                        faceHasTexCoord = true;
                    }
                    if (faceData[2].Is<Jatta::UInt32>())
                    {
                        faceHasNormal = true;
                    }
                }
                else if (faceData.size() == 2)
                {
                    if (faceData[1].Is<Jatta::UInt32>())
                    {
                        faceHasTexCoord = true;
                    }
                }
                else if (faceData.size() != 1)
                {
                    throw std::runtime_error("Invalid OBJ.  Invalid face data.");
                }
                if (first)
                {
                    hasTexCoord = faceHasTexCoord;
                    hasNormal = faceHasNormal;
                    first = false;
                }
                else
                {
                    if (hasTexCoord != faceHasTexCoord)
                    {
                        throw std::runtime_error("Invalid OBJ.  Invalid face texture coordinates.");
                    }
                    if (hasNormal != faceHasNormal)
                    {
                        throw std::runtime_error("Invalid OBJ.  Invalid face normals.");
                    }
                }
                Jatta::UInt32 positionIndex = faceData[0].To<Jatta::UInt32>() - 1;
                for (Jatta::UInt32 l = 0; l < data->positionSize; l++)
                {
                    positions[positionPos++] = data->positions[data->positionSize * positionIndex + l];
                }
                Jatta::UInt32 texCoordIndex;
                Jatta::UInt32 normalIndex;
                if (hasTexCoord)
                {
                    texCoordIndex = faceData[1].To<Jatta::UInt32>() - 1;
                    for (Jatta::UInt32 l = 0; l < data->texCoordSize; l++)
                    {
                        texCoords[texCoordPos++] = data->texCoords[data->texCoordSize * texCoordIndex + l];
                    }
                }
                if (hasNormal)
                {
                    normalIndex = faceData[2].To<Jatta::UInt32>() - 1;
                    for (Jatta::UInt32 l = 0; l < data->normalSize; l++)
                    {
                        normals[normalPos++] = data->normals[data->normalSize * normalIndex + l];
                    }
                }
                //std::cout << pos++ << std::endl;
                //pos++;
            }
            //pos++;
        }

        Jatta::VertexBuffer positionBuffer;
        positionBuffer.index = Jatta::Graphics::position1;
        positionBuffer.buffer = positions;
        positionBuffer.size = data->positionSize;
        group.AddBuffer(positionBuffer);

        if (hasTexCoord)
        {
            Jatta::VertexBuffer texCoordBuffer;
            texCoordBuffer.index = Jatta::Graphics::texCoord1;
            texCoordBuffer.buffer = texCoords;
            texCoordBuffer.size = data->texCoordSize;
            group.AddBuffer(texCoordBuffer);
        }

        if (hasNormal)
        {
            Jatta::VertexBuffer normalBuffer;
            normalBuffer.index = Jatta::Graphics::normal1;
            normalBuffer.buffer = normals;
            normalBuffer.size = data->normalSize;
            group.AddBuffer(normalBuffer);
        }
        groups.push_back(group);
    }
    return groups;
}

#include <string.h>
_JATTA_EXPORT void Jatta::Model::LoadObj(const String& fileName)
{
    Free();

    ObjData* data = new ObjData;


    Parse(data, fileName);
    std::vector<Group> groups = CreateGroups(data);

    for (auto i = groups.begin(); i != groups.end(); i++)
    {
        if (i->vertexCount != 0)
        {
            AddGroup(*i);
        }
    }

    /*static Float3 boxPositions[] = { Float3(1, -1, -1), Float3(1, 1, -1), Float3(1, -1, 1),
                              Float3(1, 1, 1), Float3(1, -1, 1), Float3(1, 1, -1),
                              Float3(-1, -1, -1), Float3(-1, -1, 1), Float3(-1, 1, -1),
                              Float3(-1, 1, 1), Float3(-1, 1, -1), Float3(-1, -1, 1),
                              Float3(-1, -1, 1), Float3(1, -1, 1), Float3(-1, 1, 1),
                              Float3(1, 1, 1), Float3(-1, 1, 1), Float3(1, -1, 1),
                              Float3(-1, -1, -1), Float3(-1, 1, -1), Float3(1, -1, -1),
                              Float3(1, 1, -1), Float3(1, -1, -1), Float3(-1, 1, -1),
                              Float3(-1, -1, -1), Float3(1, -1, -1), Float3(-1, -1, 1),
                              Float3(1, -1, 1), Float3(-1, -1, 1), Float3(1, -1, -1),
                              Float3(-1, 1, -1), Float3(-1, 1, 1), Float3(1, 1, -1),
                              Float3(1, 1, 1), Float3(1, 1, -1), Float3(-1, 1, 1) };
    static Float2 boxTexCoords[] = { Float2(1, 1), Float2(1, 0), Float2(0, 1),
                              Float2(0, 0), Float2(0, 1), Float2(1, 0),
                              Float2(1, 1), Float2(0, 1), Float2(1, 0),
                              Float2(0, 0), Float2(1, 0), Float2(0, 1),
                              Float2(1, 1), Float2(1, 0), Float2(0, 1),
                              Float2(0, 0), Float2(0, 1), Float2(1, 0),
                              Float2(1, 1), Float2(0, 1), Float2(1, 0),
                              Float2(0, 0), Float2(1, 0), Float2(0, 1),
                              Float2(1, 1), Float2(1, 0), Float2(0, 1),
                              Float2(0, 0), Float2(0, 1), Float2(1, 0),
                              Float2(1, 1), Float2(0, 1), Float2(1, 0),
                              Float2(0, 0), Float2(1, 0), Float2(0, 1) };

    VertexBuffer positionBuffer;
    positionBuffer.index = Graphics::position1;
    positionBuffer.buffer = boxPositions;
    positionBuffer.size = 3;

    VertexBuffer texCoordBuffer;
    texCoordBuffer.index = Graphics::texCoord1;
    texCoordBuffer.buffer = boxTexCoords;
    texCoordBuffer.size = 2;

    //Setup(36);
    Group blurga;
    blurga.vertexCount = 36;
    blurga.name = "blurga";
    blurga.AddBuffer(positionBuffer);
    blurga.AddBuffer(texCoordBuffer);
    AddGroup(blurga);*/

    /*for (auto i = data->groups.begin(); i != data->groups.end(); i++)
    {
        Group group;
        group.name = i->name;
        Jatta::VertexBuffer positionBuffer;
        positionBuffer.index = Jatta::Graphics::position1;
        positionBuffer.buffer = (void*)positions;
        positionBuffer.size = 3;
    }

    VertexBuffer texCoordBuffer;
    texCoordBuffer.index = Graphics::texCoord1;
    texCoordBuffer.buffer = boxTexCoords;
    texCoordBuffer.size = 2;

    Setup(36);
    AddBuffer(positionBuffer);
    AddBuffer(texCoordBuffer);*/
/*
    

    std::vector<Float4> positions;
    std::vector<Float4> texCoords;
    std::vector<Float4> normals;
    Byte positionsSize = 0;
    Byte texCoordsSize = 0;
    Byte normalsSize = 0;
    bool firstGroup = true;
    bool firstFace = true;
    Group currentGroup;
    std::vector<String> faceInfo;

    

    for (auto it = file.begin(); it != file.end(); it++)
    {
        it->Trim();
        std::vector<String> explode = it->Explode(" ", 1);
        if (explode.size() < 2)
        {
            continue;
        }
        explode[0].ToLower();
        String parameters = explode[1];
        if (explode[0] == "#") // comment
        {
            continue;
        }
        else if (explode[0] == "v") // positions
        {
            Byte size;
            Float4 position = ToVector(parameters, &size);
            if (size == 0 || size > 4)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            if (positionsSize == 0)
            {
                positionsSize = size;
            }
            else if (size != positionsSize)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            positions.push_back(position);
        }
        else if (explode[0] == "vt") // texture coordinates
        {
            Byte size;
            Float4 texCoord = ToVector(parameters, &size);
            if (size == 0 || size > 3)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            if (texCoordsSize == 0)
            {
                texCoordsSize = size;
            }
            else if (size != texCoordsSize)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            texCoords.push_back(texCoord);
        }
        else if (explode[0] == "vn") // texture normals
        {
            Byte size;
            Float4 normal = ToVector(parameters, &size);
            if (size == 0 || size > 4)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            if (normalsSize == 0)
            {
                normalsSize = size;
            }
            else if (size != normalsSize)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            normals.push_back(normal);
        }
        else if (explode[0] == "g")
        {
            if (!firstGroup)
            {
                CreateGroup(&currentGroup, faceInfo, positions, positionsSize, texCoords, texCoordsSize, normals, normalsSize);
                AddGroup(currentGroup);
                faceInfo.clear();
            }
            else
            {
                firstGroup = false;
            }
            currentGroup.name = parameters;
            firstFace = true;
        }
        else if (explode[0] == "f") // face
        {
            std::vector<Jatta::String> verts = parameters.Explode(" ");
            if (verts.size() < 3 || verts.size() > 4)
            {
                throw std::runtime_error("Invalid OBJ.");
            }
            std::istringstream ss;
            for (auto i = verts.begin(); i != verts.end(); i++)
            {
                std::vector<Jatta::String> data = i->Explode("/");
                if ((data.size() == 1 && data[0].GetSize() == 0) || data.size() < 3 || data.size() > 4)
                {
                    throw std::runtime_error("Invalid OBJ.");
                }
                else
                {
                    if (firstGroup)
                    {
                        throw std::runtime_error("Invalid OBJ.");
                    }
                    else
                    {
                        if (firstFace)
                        {
                            
                        }
                    }
                }
            }

            faceInfo.push_back(parameters);
        }
        else
        {
            _JATTA_DEBUG_LN("Unknown OBJ line: " << explode[0] << " with parameters: " << parameters);
        }
    }*/

    /*static Float3 boxPositions[] = { Float3(1, -1, -1), Float3(1, 1, -1), Float3(1, -1, 1),
                              Float3(1, 1, 1), Float3(1, -1, 1), Float3(1, 1, -1),
                              Float3(-1, -1, -1), Float3(-1, -1, 1), Float3(-1, 1, -1),
                              Float3(-1, 1, 1), Float3(-1, 1, -1), Float3(-1, -1, 1),
                              Float3(-1, -1, 1), Float3(1, -1, 1), Float3(-1, 1, 1),
                              Float3(1, 1, 1), Float3(-1, 1, 1), Float3(1, -1, 1),
                              Float3(-1, -1, -1), Float3(-1, 1, -1), Float3(1, -1, -1),
                              Float3(1, 1, -1), Float3(1, -1, -1), Float3(-1, 1, -1),
                              Float3(-1, -1, -1), Float3(1, -1, -1), Float3(-1, -1, 1),
                              Float3(1, -1, 1), Float3(-1, -1, 1), Float3(1, -1, -1),
                              Float3(-1, 1, -1), Float3(-1, 1, 1), Float3(1, 1, -1),
                              Float3(1, 1, 1), Float3(1, 1, -1), Float3(-1, 1, 1) };
    static Float2 boxTexCoords[] = { Float2(1, 1), Float2(1, 0), Float2(0, 1),
                              Float2(0, 0), Float2(0, 1), Float2(1, 0),
                              Float2(1, 1), Float2(0, 1), Float2(1, 0),
                              Float2(0, 0), Float2(1, 0), Float2(0, 1),
                              Float2(1, 1), Float2(1, 0), Float2(0, 1),
                              Float2(0, 0), Float2(0, 1), Float2(1, 0),
                              Float2(1, 1), Float2(0, 1), Float2(1, 0),
                              Float2(0, 0), Float2(1, 0), Float2(0, 1),
                              Float2(1, 1), Float2(1, 0), Float2(0, 1),
                              Float2(0, 0), Float2(0, 1), Float2(1, 0),
                              Float2(1, 1), Float2(0, 1), Float2(1, 0),
                              Float2(0, 0), Float2(1, 0), Float2(0, 1) };

    VertexBuffer positionBuffer;
    positionBuffer.index = Graphics::position1;
    positionBuffer.buffer = boxPositions;
    positionBuffer.size = 3;

    VertexBuffer texCoordBuffer;
    texCoordBuffer.index = Graphics::texCoord1;
    texCoordBuffer.buffer = boxTexCoords;
    texCoordBuffer.size = 2;

    Setup(36);
    AddBuffer(positionBuffer);
    AddBuffer(texCoordBuffer);*/
}

#if 0
#include "Obj.h"
#include "Group.h"
#include "../File/File.h"
#include "../Math/Math.h"
#include "../Math/Float4.h"

_JATTA_EXPORT void Jatta::Obj::CleanLine(std::string* line)
{
    size_t find;
    while ((find = line->find("  ")) != std::string::npos)
    {
        line->erase(find, 1);
    }
    if (*line->begin() == ' ')
    {
        line->erase(line->begin());
    }
    if (*(line->end() - 1) == ' ')
    {
        line->erase(line->end() - 1);
    }
}

_JATTA_EXPORT bool Jatta::Obj::GetParameters(const std::string& parameters, float* data, unsigned int* size)
{
    std::istringstream ss;
    ss.str(parameters);
    for (*size = 0; *size < 4 && ss.good(); (*size)++)
    {
        ss >> data[*size];
    }
    return true; // TODO: check for errors
}

_JATTA_EXPORT bool Jatta::Obj::GetParameters(const std::string& parameters)//, std::vector<std::pair<float*, unsigned int>>* data)
{
    std::string number = "";
    for (unsigned int i = 0; i <= parameters.size(); i++)
    {
        if (i == parameters.size() || !isdigit(parameters[i]))
        {
            _JATTA_DEBUG_LN(number);
            number = "";
            continue;
        }
        number += parameters[i];
    }
    return true; // TODO: check for errors
}

_JATTA_EXPORT Jatta::Obj::Obj()
{
}

_JATTA_EXPORT bool Jatta::Obj::Load(const std::string& fileName)
{
    std::vector<std::string> file;
    if (!File::GetLines(fileName, &file))
    {
        return false;
    }

    unsigned int verticesCount = 0;
    std::vector<Jatta::Float4> vertices;
    unsigned int texCoordCount = 0;
    std::vector<Jatta::Float4> texCoords;
    Group* group = nullptr;

    for (auto it = file.begin(); it != file.end(); it++)
    {
        std::string clean = *it;
        CleanLine(&clean);
        if (clean.empty() || clean.at(0) == '#')
        {
            continue;
        }
        size_t find = clean.find(' ');
        if (find == std::string::npos)
        {
            continue;
        }
        std::string type = clean.substr(0, find);
        std::string parameters = clean.substr(find + 1);
        float vector[4];
        unsigned int vectorSize;
        //std::cout << type << std::endl;
        if (type == "v")
        {
            GetParameters(parameters, vector, &vectorSize);
            if (vectorSize != verticesCount)
            {
                if (verticesCount == 0)
                {
                    verticesCount = vectorSize;
                }
                else
                {
                    return false;
                }
            }
            vertices.push_back(*(Float4*)vector);
        }
        else if (type == "vt")
        {
            GetParameters(parameters, vector, &vectorSize);
            if (vectorSize != texCoordCount)
            {
                if (texCoordCount == 0)
                {
                    texCoordCount = vectorSize;
                }
                else
                {
                    return false;
                }
            }
            texCoords.push_back(*(Float4*)vector);
        }
        else if (type == "g")
        {
            groups.push_back(Group());
            group = &(*(groups.end() - 1));
            group->name = parameters;
        }
        else if (type == "f")
        {
            if (group == nullptr)
            {
                return false;
            }
            GetParameters(parameters);
        }
    }

    _JATTA_DEBUG_LN("GROUPS: " << groups.size());

    return true;
}
#endif
