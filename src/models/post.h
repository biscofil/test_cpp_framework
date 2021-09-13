#ifndef POST
#define POST

#include "../system/model.h"

class Post : public Model
{
    int id = 1;

public:
    std::string serialize() override
    {
        return "{'id' : " + std::to_string(id) + "}";
    }
};

#endif POST