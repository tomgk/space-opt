#include "numberstring.h"

#include<stdexcept>

template<size_t N>
int NumberCharset<N>::parseDigit(const char *str, size_t index)
{
    char ch = str[index];
    if(ch < '0' || ch >= '9')
        throw std::invalid_argument(std::string()+"invalid: "+str+" - digit DEC"+std::to_string(int(ch)));

    return ch - '0';
}

template<size_t N>
char NumberCharset<N>::toDigit(int value)
{
    return value + '0';
}

template class NumberCharset<10>;
