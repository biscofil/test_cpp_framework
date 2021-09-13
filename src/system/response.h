#ifndef RESPONSES
#define RESPONSES

#include <stdio.h>
#include <iostream>
#include <string>
#include "serializable.h"

class JsonResponse
{
    std::string out;

public:
    JsonResponse(std::string content) : out(content)
    {
    }

    JsonResponse(Serializable &content) : out(content.serialize())
    {
    }

    void serialize()
    {
        std::cout << out << std::endl;
    }
};

#endif