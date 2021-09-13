#ifndef MODEL
#define MODEL

#include "serializable.h"

class Model : public Serializable
{

public:
    bool update()
    {
        return false;
    }
};

#endif MODEL