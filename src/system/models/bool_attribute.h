#ifndef BOOL_ATTRIBUTE
#define BOOL_ATTRIBUTE

#include <vector>
#include <string>
#include "attribute.h"

class BoolAttribute : public Attribute<bool, BoolAttribute>
{

    bool fromDatabaseValue(std::string value) override
    {
        return value == "1" || value == "true";
    }

    std::string toDatabaseValue(bool value) override
    {
        return value ? "1" : "0";
    }
};

#endif