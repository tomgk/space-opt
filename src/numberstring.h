#ifndef NUMBERSTRING_H
#define NUMBERSTRING_H

#include "nibblestring.h"

template<size_t N>
class NumberCharset
{
public:
    static int getCharValue(const char *str, size_t index);
    static char toChar(int value);
};

using DecimalString = NibbleString<NumberCharset<10>>;
using HexString = NibbleString<NumberCharset<16>>;

#endif // NUMBERSTRING_H
