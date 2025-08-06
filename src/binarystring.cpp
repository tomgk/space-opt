#include "binarystring.h"

#include<stdexcept>
#include<cstring>

template<typename Collection, char F, char T>
bool BasicBinaryString<Collection, F, T>::toBool(char ch)
{
    if(ch == FALSE)
        return false;
    else if(ch == TRUE)
        return true;
    else
        throw std::invalid_argument("Invalid value: "+std::string(1, ch));
        //throw std::invalid_argument("Invalid value at index "+std::to_string(i)+": "+ch+" - full string is "+str);
}

template<typename Collection, char F, char T>
char BasicBinaryString<Collection, F, T>::toChar(bool b)
{
    return b ? TRUE : FALSE;
}

template<typename Collection, char F, char T>
BasicBinaryString<Collection, F, T>::BasicBinaryString(const char *str)
{
    size_t size = strlen(str);
    for(size_t i = 0; i < size; ++i)
    {
        char c = str[i];
        bool v = toBool(c);

        data.push_back(v);
    }
}

template<typename Collection, char F, char T>
int BasicBinaryString<Collection, F, T>::size() const
{
    return data.size();
}

template<typename Collection, char F, char T>
int BasicBinaryString<Collection, F, T>::size()
{
    return data.size();
}

template<typename Collection, char F, char T>
int BasicBinaryString<Collection, F, T>::concat_capacity() const
{
    return data.capacity();
}

template<typename Collection, char F, char T>
char BasicBinaryString<Collection, F, T>::at(size_t index) const
{
    return toChar(data.at(index));
}

template<typename Collection, char F, char T>
std::string BasicBinaryString<Collection, F, T>::str() const
{
    std::string str;
    str.reserve(data.size());
    for(bool b : data)
        str += toChar(b);
    return str;
}

template<typename Collection, char F, char T>
BasicBinaryString<Collection, F, T> &BasicBinaryString<Collection, F, T>::operator+=(char c)
{
    data.push_back(toBool(c));
    return *this;
}

template<typename Collection, char F, char T>
void BasicBinaryString<Collection, F, T>::write(std::ostream &out) const
{
    for(bool b : data)
        out.put(toChar(b));
}

template class BasicBinaryString<>;
