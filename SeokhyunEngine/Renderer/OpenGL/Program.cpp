#include "Program.h"

Program::Program()
{

}

Program::~Program()
{

}

bool Program::linkShaders(const std::vector<Shader*> &shaders)
{
    m_program = glCreateProgram();

    for (auto& shader : shaders)
    {
        glAttachShader(m_program, shader->get());
    }

    glLinkProgram(m_program);

    int success = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        char infoLog[1024];
        glGetProgramInfoLog(m_program, 1024, nullptr, infoLog);

        std::cout << "[ERROR] failed to link program: " << infoLog << std::endl;
        return false;
    }

    return true;
}

Program *Program::Create(const std::string &vertShaderFilename, const std::string &fragShaderFilename)
{
    Shader* vs = Shader::Create(vertShaderFilename, GL_VERTEX_SHADER);
    Shader* fs = Shader::Create(fragShaderFilename, GL_FRAGMENT_SHADER);

    if (!vs || !fs)
    {
        return nullptr;
    }

    return Create({vs, fs});
}

Program *Program::Create(const std::vector<Shader*> &shaders)
{
    auto program = new Program();

    if (!program->linkShaders(shaders))
    {
        return nullptr;
    }

    return program;
}

void Program::use() const
{
    glUseProgram(m_program);
}

void Program::setUniform(const std::string& name, int value) const
{
    auto loc = glGetUniformLocation(m_program, name.c_str());
    glUniform1i(loc, value);
}

void Program::setUniform(const std::string &name, float value) const
{
    auto loc = glGetUniformLocation(m_program, name.c_str());
    glUniform1f(loc, value);
}

void Program::setUniform(const std::string &name, const glm::vec2 &value) const
{
    auto loc = glGetUniformLocation(m_program, name.c_str());
    glUniform2fv(loc, 1, glm::value_ptr(value));
}

void Program::setUniform(const std::string &name, const glm::vec3 &value) const
{
    auto loc = glGetUniformLocation(m_program, name.c_str());
    glUniform3fv(loc, 1, glm::value_ptr(value));
}

void Program::setUniform(const std::string &name, const glm::vec4 &value) const
{
    auto loc = glGetUniformLocation(m_program, name.c_str());
    glUniform4fv(loc, 1, glm::value_ptr(value));
}

void Program::setUniform(const std::string &name, const glm::mat4 &value) const
{
    auto loc = glGetUniformLocation(m_program, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

std::string Program::getErrorLog() const
{
    GLint length;
    glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &length);

    char* infoLog = (char*) malloc(sizeof(char) * length);
    glGetProgramInfoLog(m_program, length, nullptr, infoLog);

    return {infoLog};
}

