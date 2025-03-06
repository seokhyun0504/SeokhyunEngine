#ifndef __FILEREADER_H__
#define __FILEREADER_H__

#include <iostream>
#include <fstream>
#include <sstream>

std::optional<std::string> ReadFile(const std::string &filename)
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

#endif //__FILEREADER_H__
