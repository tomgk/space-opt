#include "numberstring.h"

#include<stdexcept>

static const char ALPHA_START = 'A';
static const char ALPHA_END   = 'Z';
static int ALPHA_LEN = ALPHA_END - ALPHA_START;

static std::invalid_argument raiseInvalid(char ch)
{
    return std::invalid_argument(std::string("invalid: DEC"+std::to_string(int(ch))));
}

template<size_t N>
int NumberCharset<N>::getCharValue(char ch)
{
    if(N <= 10)
    {
        if(ch < '0' || ch > '9')
            throw raiseInvalid(ch);

        return ch - '0';
    }
    else
    {
        if(ch >= '0' && ch <= '9')
            return ch - '0';
        else if(ch >= ALPHA_START && ch <= ALPHA_END)
            return ch - ALPHA_START + 10;
        else
            throw raiseInvalid(ch);
    }
}

template<size_t N>
char NumberCharset<N>::toChar(int value)
{
    if(N <= 10)
        return value + '0';
    else
    {
        if(value < 10)
            return value + '0';
        else if(value >= 10 && value < 26)
            return ALPHA_START + (value - 10);
        else
            throw std::invalid_argument("invalid: "+std::to_string(value));
    }
}

template class NumberCharset<10>;
template class NumberCharset<16>;
