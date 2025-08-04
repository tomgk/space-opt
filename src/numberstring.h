#ifndef NUMBERSTRING_H
#define NUMBERSTRING_H

#include "nibblestring.h"
#include "digitcharset.h"

using DecimalString = NibbleString<DigitCharset<10>>;
using HexString = NibbleString<DigitCharset<16>>;

#endif // NUMBERSTRING_H
