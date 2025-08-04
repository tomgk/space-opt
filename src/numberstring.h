#ifndef NUMBERSTRING_H
#define NUMBERSTRING_H

#include "nibblestring.h"

std::invalid_argument raiseInvalid(char ch);

template<size_t N>
class DigitCharset
{
    static constexpr char ALPHA_START = 'A';
    static constexpr char ALPHA_END   = 'Z';
    static constexpr int ALPHA_LEN = ALPHA_END - ALPHA_START;
public:
    static int getCharValue(char ch)
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

    static char toChar(int value)
    {
        if(value >= N)
            throw std::invalid_argument("too high: "+std::to_string(value));

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
};

template class DigitCharset<10>;
template class DigitCharset<16>;

using DecimalString = NibbleString<DigitCharset<10>>;
using HexString = NibbleString<DigitCharset<16>>;

#endif // NUMBERSTRING_H
