#ifndef BINARYSTRING_H
#define BINARYSTRING_H

#include<vector>
#include<cstddef>

class BinaryString
{
    std::vector<bool> data;
public:
    BinaryString(const char *str);
    int size() const
    {
        return data.size();
    }
    int size()
    {
        return data.size();
    }

    int concat_capacity() const
    {
        return data.capacity();
    }
};

#endif // BINARYSTRING_H
