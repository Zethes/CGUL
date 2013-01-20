/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "SubMesh.h"
#include "Graphics.h"
#include "../Models/Model.h"
#include "../Images/Image.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
#include "../External/Defines.h"

namespace Jatta
{
	class Terrain
	{
	private:
		SubMesh mesh;
		std::vector<Texture*>textures;
		std::vector<std::vector<Color> > mixmap;
		int numTextures; //Max of 14 textures.

		int numTriangles;
		Float3*vectorPositions;
		UInt32*indexBuffer;
		Float2*textureCoords;

		int width, height;

		float hScale, bScale;
	public:
		_JATTA_EXPORT Terrain(float heightScale = 0.5f, float blockScale = 2.0f);

		_JATTA_EXPORT bool LoadHeightmap(Image* hmap, Float2 textureSize);
		_JATTA_EXPORT void AddTexture(Texture* texture, std::vector<Color>mixmap);
		_JATTA_EXPORT void Build();

		_JATTA_EXPORT int GetWidth();
		_JATTA_EXPORT int GetHeight();
		_JATTA_EXPORT float GetHeightAt(const Float2 position);

		_JATTA_EXPORT Texture* GetTexture(int id);

		_JATTA_EXPORT void Draw(Jatta::Shader*shader);
	};
}


#include "../External/Undefines.h"
