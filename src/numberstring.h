#ifndef NUMBERSTRING_H
#define NUMBERSTRING_H

#include "nibblestring.h"

std::invalid_argument raiseInvalid(char ch);

template<size_t N>
class DigitCharset
{
    static constexpr char NUM_START = '0';
    static constexpr int NUM_COUNT = 10;

    static constexpr char ALPHA_START = 'A';
    static constexpr int ALPHA_COUNT = 10;

    static_assert(N >= 2);
    static_assert(N <= NUM_COUNT + ALPHA_COUNT);
public:
    static int getCharValue(char ch)
    {
        if constexpr(N <= NUM_COUNT)
        {
            char numMax = NUM_START+N;

            if(ch < NUM_START || ch > numMax)
                throw raiseInvalid(ch);

            return ch - NUM_START;
        }
        else
        {
            const char MAX_ALPHA = ALPHA_START + (N - NUM_COUNT);

            if(ch >= NUM_START && ch <= NUM_START+NUM_COUNT)
                return ch - NUM_START;
            else if(ch >= ALPHA_START && ch <= MAX_ALPHA)
                return ch - ALPHA_START + NUM_COUNT;
            else
                throw raiseInvalid(ch);
        }
    }

    static char toChar(int value)
    {
        if(value >= N)
            throw std::invalid_argument("too high: "+std::to_string(value));

        if constexpr(N <= NUM_COUNT)
            return value + NUM_START;
        else
        {
            const char MAX_ALPHA = ALPHA_START + (N - NUM_COUNT);

            if(value < NUM_COUNT)
                return value + NUM_START;
            else if(value >= NUM_COUNT && value < MAX_ALPHA)
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
