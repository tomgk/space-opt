#include "binarystring.h"

#include<stdexcept>
#include<cstring>

template<typename Collection>
bool BasicBinaryString<Collection>::toBool(char ch)
{
    if(ch == '0')
        return false;
    else if(ch == '1')
        return true;
    else
        throw std::invalid_argument("Invalid value: "+std::string(1, ch));
        //throw std::invalid_argument("Invalid value at index "+std::to_string(i)+": "+ch+" - full string is "+str);
}

template<typename Collection>
char BasicBinaryString<Collection>::toChar(bool b)
{
    return b ? '1' : '0';
}

template<typename Collection>
BasicBinaryString<Collection>::BasicBinaryString(const char *str)
{
    size_t size = strlen(str);
    for(size_t i = 0; i < size; ++i)
    {
        char c = str[i];
        bool v = toBool(c);

        data.push_back(v);
    }
}

template<typename Collection>
int BasicBinaryString<Collection>::size() const
{
    return data.size();
}

template<typename Collection>
int BasicBinaryString<Collection>::size()
{
    return data.size();
}

template<typename Collection>
int BasicBinaryString<Collection>::concat_capacity() const
{
    return data.capacity();
}

template<typename Collection>
char BasicBinaryString<Collection>::at(size_t index) const
{
    return toChar(data.at(index));
}

template<typename Collection>
std::string BasicBinaryString<Collection>::str() const
{
    std::string str;
    str.reserve(data.size());
    for(bool b : data)
        str += toChar(b);
    return str;
}

template<typename Collection>
BasicBinaryString<Collection> &BasicBinaryString<Collection>::operator+=(char c)
{
    data.push_back(toBool(c));
    return *this;
}

template<typename Collection>
void BasicBinaryString<Collection>::write(std::ostream &out) const
{
    for(bool b : data)
        out.put(toChar(b));
}

template class BasicBinaryString<>;
