#ifndef DIGITSTRING_H
#define DIGITSTRING_H

#include "nibblestring.h"

class DecimalCharset
{
public:
    static int parseDigit(const char *str, size_t index);
    static char toDigit(int value);
};

using DecimalString = NibbleString<DecimalCharset>;

#endif // DIGITSTRING_H
