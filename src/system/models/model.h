#ifndef MODEL
#define MODEL

#include "../serializable.h"
#include "int_attribute.h"
#include "collection.h"

template <typename T>
class Model : public Serializable
{

public:
    IntAttribute id;

    bool update()
    {
        // TODO
        return false;
    }

    bool save()
    {

        // TODO
        return false;
    }

    static Collection<T> all()
    {
        Collection<T> out;
        for (int i = 0; i < 5; i++)
        {
            T c = T();
            c.id.set(i + 1);
            out.add(c); // TODO
        }
        return out;
    }
};

#endif MODEL