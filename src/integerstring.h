#ifndef INTEGERSTRING_H
#define INTEGERSTRING_H

#include "nibblestring.h"
#include "digitcharset.h"

using DecimalString = NibbleString<DigitCharset<10>>;
using HexString = NibbleString<DigitCharset<16>>;

#endif // INTEGERSTRING_H
