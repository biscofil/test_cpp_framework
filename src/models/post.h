#ifndef POST
#define POST

#include "../system/models/model.h"
#include "../system/models/int_attribute.h"
#include "../system/models/bool_attribute.h"

class Post : public Model<Post>
{

public:

    BoolAttribute approved;

    std::string serialize() override
    {
        return "{'id' : " + id.serialize() + ", 'approved' : " + approved .serialize() + "}";
    }
};

#endif POST