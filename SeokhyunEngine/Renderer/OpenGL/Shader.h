#ifndef __SHADER_H__
#define __SHADER_H__

#include "common.h"

#include <fstream>
#include <sstream>

class Shader
{

private:

    GLuint m_shader = 0;

    Shader();

    bool compile(const std::string& filename, GLenum shaderType);


public:

    ~Shader();

    static Shader* Create(const std::string& filename, GLenum shaderType);

    std::optional<std::string> ReadFile(const std::string &filename);

    const GLuint get() const { return m_shader; }
    std::string getErrorLog() const;
};


#endif //__SHADER_H__
