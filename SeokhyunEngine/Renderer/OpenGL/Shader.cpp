#include "Shader.h"

Shader::Shader()
{

}

Shader::~Shader()
{
    if (m_shader)
        glDeleteShader(m_shader);
}

bool Shader::compile(const std::string &filename, GLenum shaderType)
{
    auto source = ReadFile(filename);
    if (!source.has_value()) return false;

    auto& code = source.value();
    const GLchar* codePtr = code.c_str();
    int codeLength = (int)code.length();

    m_shader = glCreateShader(shaderType);

    glShaderSource(m_shader, 1, (const GLchar* const*)&codePtr, &codeLength);
    glCompileShader(m_shader);

    int success = 0;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char infoLog[1024];
        glGetShaderInfoLog(m_shader, 1024, nullptr, infoLog);

        std::cout << "[ERROR] failed to compile " << filename << " reason: " << infoLog << std::endl;
        return false;
    }

    return true;
}

Shader *Shader::Create(const std::string &filename, GLenum shaderType)
{
    auto shader = new Shader();

    if (!shader->compile(filename, shaderType))
    {
        return nullptr;
    }

    return shader;
}

std::optional<std::string> Shader::ReadFile(const std::string &filename)
{
    std::ifstream fin(filename);

    if (!fin.is_open())
    {
        std::cout << "[ERROR] Failed to open file: " << filename << std::endl;
        return {};
    }

    std::stringstream text;
    text << fin.rdbuf();

    return text.str();
}

std::string Shader::getErrorLog() const
{
    GLint length;
    glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &length);

    char* infoLog = (char*) malloc(sizeof(char) * length);
    glGetShaderInfoLog(m_shader, length, nullptr, infoLog);

    return {infoLog};
}
