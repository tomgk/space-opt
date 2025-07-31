#ifndef FLOATSTRING_H
#define FLOATSTRING_H

#include "numberstring.h"

template<typename S>
class FloatStringTpl
{
    S m_digits;
    size_t m_pos;
public:
    FloatStringTpl(std::string_view str)
    {
        bool foundPos = false;

        std::string digits;

        size_t index = 0;
        for(char c : str)
        {
            if(c == '.')
            {
                if(foundPos)
                    throw std::invalid_argument("double comma");

                foundPos = true;
                m_pos = index;
            }
            else
                digits += c;

            ++index;
        }
    }
};

using FloatDecimalString = FloatStringTpl<DecimalString>;
using FloatHexString = FloatStringTpl<HexString>;

#endif // FLOATSTRING_H
