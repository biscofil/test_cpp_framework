#ifndef ATTRIBUTE
#define ATTRIBUTE

#include <vector>
#include <string>
#include "../serializable.h"

template <typename T, typename O>
class Attribute : public Serializable
{

    bool dirty = false;

protected:
    T original_value;
    T value;

public:

    O& set(const T &v)
    {
        value = v;
        dirty = value != original_value;
        return dynamic_cast<O&>(*this);
    }

    O& operator=(const T &v)
    {
        return set(v);
    }

    std::string serialize() override
    {
        return toDatabaseValue(value);
    }

    virtual T fromDatabaseValue(std::string value) = 0;

    virtual std::string toDatabaseValue(T value) = 0;
};

#endif