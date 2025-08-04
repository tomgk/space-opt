#include "binarystring.h"

#include<stdexcept>
#include<cstring>

BinaryString::BinaryString(const char *str)
{
    size_t size = strlen(str);
    for(size_t i = 0; i < size; ++i)
    {
        char c = str[i];
        bool v;
        if(c == '0')
            v = false;
        else if(c == '1')
            v = true;
        else
            throw std::invalid_argument("Invalid value at index "+std::to_string(i)+": "+c+" - full string is "+str);

        data.push_back(v);
    }
}
