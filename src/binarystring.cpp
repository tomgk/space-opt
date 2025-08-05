#include "binarystring.h"

#include<stdexcept>
#include<cstring>

bool BinaryString::toBool(char ch)
{
    if(ch == '0')
        return false;
    else if(ch == '1')
        return true;
    else
        throw std::invalid_argument("Invalid value: "+std::string(1, ch));
        //throw std::invalid_argument("Invalid value at index "+std::to_string(i)+": "+ch+" - full string is "+str);
}

char BinaryString::toChar(bool b)
{
    return b ? '1' : '0';
}

BinaryString::BinaryString(const char *str)
{
    size_t size = strlen(str);
    for(size_t i = 0; i < size; ++i)
    {
        char c = str[i];
        bool v = toBool(c);

        data.push_back(v);
    }
}

int BinaryString::size() const
{
    return data.size();
}

int BinaryString::size()
{
    return data.size();
}

int BinaryString::concat_capacity() const
{
    return data.capacity();
}

char BinaryString::at(size_t index) const
{
    return toChar(data.at(index));
}

std::string BinaryString::str() const
{
    std::string str;
    str.reserve(data.size());
    for(bool b : data)
        str += toChar(b);
    return str;
}

void BinaryString::write(std::ostream &out) const
{
    for(bool b : data)
        out.put(toChar(b));
}
