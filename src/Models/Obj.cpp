/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
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

 struct ObjFace
 {

 };

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

#include <string.h>
void Jatta::Model::LoadObj(const std::string& fileName)
{
	Free();

	std::vector<String> file;
	if (!File::GetLines(fileName, &file))
	{
		return;
	}

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
