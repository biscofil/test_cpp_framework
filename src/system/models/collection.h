#ifndef COLLECTION
#define COLLECTION

#include <vector>
#include "../serializable.h"

template <typename T> // , typename = std::enable_if<std::is_base_of<Serializable, T>::value>
class Collection : public Serializable
{

    std::vector<T> items;

public:
    void add(T item)
    {
        items.push_back(item);
    }

    std::string serialize() override
    {
        std::string out = "[";
        bool first = true;
        for (auto item : items)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                out += ","; // TODO except the last
            }
            out += item.serialize();
        }
        return out + "]";
    }
};

#endif