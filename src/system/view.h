#ifndef VIEW
#define VIEW

#include <string>
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream
#include <streambuf>
#include "serializable.h"

class View : public Serializable
{
    std::string path;

public:
    View(std::string p) : path(p)
    {
    }

    std::string serialize() override
    {
        auto _path = std::string("src/views/") + path; // TODO sanitize path
        std::ifstream t(_path);
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }
};

#endif