#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "common.h"

class Texture
{

private:

    GLuint m_texture = 0;

    GLint m_minFilter { GL_LINEAR };
    GLint m_magFilter { GL_LINEAR };

    GLint m_sWrapMode { GL_REPEAT };
    GLint m_tWrapMode { GL_REPEAT };


    Texture();

    void initTexture();
    bool setImage(const char * imageDir, bool flipVertical = true);


public:

    ~Texture();

    static Texture* Create(const char * imageDir, bool flipVertical = true);


    void setFilter(GLint minFilter, GLint magFilter);
    void setWrapMode(GLint sWrap, GLint tWrap);

    const GLuint get() const { return m_texture; }
};


#endif //__TEXTURE_H__
