/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "RenderTarget.h"

Jatta::RenderTarget::Viewport Jatta::RenderTarget::viewport;

_JATTA_EXPORT Jatta::RenderTarget::RenderTarget()
{
    textures = nullptr;
}

_JATTA_EXPORT Jatta::RenderTarget::~RenderTarget()
{
    delete[] textures;
}

_JATTA_EXPORT void Jatta::RenderTarget::Create(UInt32 width, UInt32 height, UInt32 textures)
{
    this->width = width;
    this->height = height;
    this->textureCount = textures;

    this->textures = new UInt32[textures];

    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

    glGenTextures(textures, this->textures);

    for (UInt32 i = 0; i < textures; i++)
    {
        glBindTexture(GL_TEXTURE_2D, this->textures[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, this->textures[i], 0);
    }

    glGenRenderbuffers(1, &renderBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderBuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status == GL_FRAMEBUFFER_UNDEFINED)
	{
		_JATTA_DEBUG_LN("Error: You are using the default framebuffer.\n");
	}
	else if (status == GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
	{
		_JATTA_DEBUG_LN("Error: The framebuffer's attachement points are incomplete.\n");
	}
	else if (status == GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
	{
		_JATTA_DEBUG_LN("Error: The framebuffer's missing a texture attachment.\n");
	}
	else if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		_JATTA_DEBUG_LN("Error: Unknown error with framebuffer.");
	}
}

_JATTA_EXPORT void Jatta::RenderTarget::Begin()
{
	glGetIntegerv(GL_VIEWPORT, viewport.vp);
	glViewport(0, 0, width, height);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);

	/*if (textureCount > 1)
	{
		GLenum* buffers = new GLenum[textureCount];
		for (unsigned int i = 0; i < textureCount; i++)
		{
			buffers[i] = GL_COLOR_ATTACHMENT0 + i;
		}
		glDrawBuffers(textureCount, buffers);
		delete[] buffers;
	}*/
}

_JATTA_EXPORT void Jatta::RenderTarget::End()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::RenderTarget::GetTexture(UInt32 index) const
{
	return textures[index];
}
