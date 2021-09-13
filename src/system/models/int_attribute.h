#ifndef INT_ATTRIBUTE
#define INT_ATTRIBUTE

#include <vector>
#include <string>
#include "attribute.h"

class IntAttribute : public Attribute<int, IntAttribute>
{
public:
    int fromDatabaseValue(std::string value) override
    {
        return std::stoi(value);
    }

    std::string toDatabaseValue(int value) override
    {
        return std::to_string(value);
    }
};

#endif