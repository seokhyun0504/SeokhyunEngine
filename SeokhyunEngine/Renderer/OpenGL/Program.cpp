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

std::string Program::getErrorLog() const
{
    GLint length;
    glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &length);

    char* infoLog = (char*) malloc(sizeof(char) * length);
    glGetProgramInfoLog(m_program, length, nullptr, infoLog);

    return {infoLog};
}

