/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Terrain.h"
#include <iostream>

_JATTA_EXPORT Jatta::Terrain::Terrain(float heightScale, float blockScale)
{
	textures.clear();
	mixmap.clear();

	numTextures = 0;

	hScale = heightScale;
	bScale = blockScale;
}

_JATTA_EXPORT bool Jatta::Terrain::LoadHeightmap(Image* hmap, Float2 textureSize)
{
	Color* data = (Color*)hmap->GetData();

	width = hmap->GetWidth();
	height = hmap->GetHeight();

	vectorPositions = new Float3[width*height];
	textureCoords = new Float2[width*height];

	float terrainWidth = (width-1)*bScale;
	float terrainHeight = (height-1)*bScale;

	for (unsigned int j = 0; j < height; j++)
	{
		for (unsigned int i = 0; i < width; i++)
		{
			unsigned int index = (j*width)+i;
			float heightValue = data[index].r;

			float u = (i/(float)(textureSize.x));
			float v = (j/(float)(textureSize.y));

			float x = (u*terrainWidth) - terrainWidth/2;
			float y = heightValue * hScale;
			float z = (v*terrainHeight) - terrainHeight/2;

			vectorPositions[index] = Float3(x,y,z);

			textureCoords[index] = Float2(u,v);
		}
	}

	//Build index buffer.
	numTriangles = (width-1)*(height-1)*2;
	indexBuffer = new UInt32[numTriangles*3];
	unsigned int index = 0;
	for (unsigned int j = 0; j < height-1; j++)
	{
		for (unsigned int i = 0; i < width-1; i++)
		{
			int vertexIndex = (j*width)+i;
			indexBuffer[index++] = vertexIndex;
			indexBuffer[index++] = vertexIndex+width+1;
			indexBuffer[index++] = vertexIndex+1;

			indexBuffer[index++] = vertexIndex;
			indexBuffer[index++] = vertexIndex+width;
			indexBuffer[index++] = vertexIndex+width+1;
		}
	}
	numTriangles/=2;

	return true;
}
_JATTA_EXPORT void Jatta::Terrain::AddTexture(Texture* texture, std::vector<Color>tmap)
{
	if (numTextures < 13) //Max is 12
	{
		textures.push_back(texture);
		mixmap.push_back(tmap);
		numTextures++;
	}
}

_JATTA_EXPORT void Jatta::Terrain::Build()
{
	mesh.Setup(SubMesh::Type::TRIANGLES, numTriangles);

	//Bind textures.
	int index = 0;
	for (int i = 0; i < mixmap.size() && index < 13; i++)
	{
		Color*mmap = new Color[width*height];

		for (unsigned int j = 0; j < width*height; j++)
		{
			if (i < mixmap.size())
			{ mmap[j] = (Color)mixmap[i][j]; }
			else
			{ mmap[j] = (Color)Color(255,255,255,0); }
		}


		mesh.AddBuffer(mmap, index);
		index++;
	}
	mesh.SetIndexBuffer(indexBuffer,numTriangles*3);
	mesh.AddBuffer(textureCoords, 14);
	mesh.AddBuffer(vectorPositions, 15);
}

_JATTA_EXPORT int Jatta::Terrain::GetWidth()
{
	return width;
}
_JATTA_EXPORT int Jatta::Terrain::GetHeight()
{
	return height;
}

_JATTA_EXPORT float Jatta::Terrain::GetHeightAt(const Float2 position)
{
	//TODO: Better.
	return vectorPositions[int(position.x*width+position.y)].y;
}

_JATTA_EXPORT Jatta::Texture* Jatta::Terrain::GetTexture(int id)
{
	return textures[id];
}

_JATTA_EXPORT void Jatta::Terrain::Draw(Jatta::Shader*shader)
{
	//Bind textures.
	for (int i = 0; i < textures.size(); i++)
	{
		Jatta::String str = "tex";
		str += (int)i;
		shader->SetTexture(str.GetData(),*textures[i]);
	}

	mesh.Draw();
}

