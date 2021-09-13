#ifndef RESPONSES
#define RESPONSES

#include <stdio.h>
#include <iostream>
#include <string>

class JsonResponse
{
    std::string out;

public:
    JsonResponse(std::string content) : out(content)
    {
    }

    void serialize()
    {
        std::cout << out << std::endl;
    }
};

#endif