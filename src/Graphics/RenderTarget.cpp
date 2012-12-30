#include "RenderTarget.h"

Jatta::RenderTarget::Viewport Jatta::RenderTarget::viewport;

Jatta::RenderTarget::RenderTarget()
{
    textures = nullptr;
}

Jatta::RenderTarget::~RenderTarget()
{
    delete[] textures;
}

void Jatta::RenderTarget::create(UInt32 width, UInt32 height, UInt32 textures)
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

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Jatta::RenderTarget::begin()
{
}

void Jatta::RenderTarget::end()
{
}