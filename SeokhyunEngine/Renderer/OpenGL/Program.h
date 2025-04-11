#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "common.h"
#include "Renderer/OpenGL/Shader.h"

#include <vector>

class Program
{

private:

    GLuint m_program = 0;

    Program();

    bool linkShaders(const std::vector<Shader*>& shaders);


public:

    ~Program();

    static Program* Create(const std::string& vertShaderFilename, const std::string& fragShaderFilename);
    static Program* Create(const std::vector<Shader*>& shaders);

    void use() const;

    void setUniform(const std::string& name, int value) const;
    void setUniform(const std::string& name, float value) const;
    void setUniform(const std::string& name, const glm::vec2& value) const;
    void setUniform(const std::string& name, const glm::vec3& value) const;
    void setUniform(const std::string& name, const glm::vec4& value) const;
    void setUniform(const std::string& name, const glm::mat4& value) const;

    std::string getErrorLog() const;
    const GLuint get() const { return m_program; }
};


#endif //__PROGRAM_H__
