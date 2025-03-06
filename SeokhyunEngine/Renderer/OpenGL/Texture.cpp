#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

Texture::Texture()
{

}

Texture::~Texture()
{
    if (m_texture)
        glDeleteTextures(1, &m_texture);
}

void Texture::initTexture()
{
    glGenTextures(1, &m_texture);

    glBindTexture(GL_TEXTURE_2D, m_texture);

    setFilter(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    setWrapMode(GL_REPEAT, GL_REPEAT);
}

bool Texture::setImage(const char *imageDir, bool flipVertical)
{
    stbi_set_flip_vertically_on_load(flipVertical);

    int width, height, channelCount;
    unsigned char* data = stbi_load(imageDir, &width, &height, &channelCount, 4);

    if (!data)
    {
        std::cerr << "[ERROR] failed to load image at" << imageDir << "\n";
        return false;
    }

    stbi_image_free(data);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB8_ALPHA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    return true;
}

Texture *Texture::Create(const char *imageDir, bool flipVertical)
{
    auto texture = new Texture();

    texture->initTexture();
    if (!texture->setImage(imageDir, flipVertical))
    {
        return nullptr;
    }

    return texture;
}

void Texture::setFilter(GLint minFilter, GLint magFilter)
{
    m_minFilter = minFilter; m_magFilter = magFilter;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_magFilter);
}

void Texture::setWrapMode(GLint sWrap, GLint tWrap)
{
    m_sWrapMode = sWrap; m_tWrapMode = tWrap;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_sWrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_tWrapMode);
}
