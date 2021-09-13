#ifndef SERIALIZABLE
#define SERIALIZABLE

#include <string.h>

class Serializable
{
public:
    virtual std::string serialize() = 0;
};

#endif SERIALIZABLE