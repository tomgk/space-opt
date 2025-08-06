#include "nibblestring.h"

#include "digitcharset.h"

static void a()
{
    using BinStr = NibbleString<DigitCharset<2>>;

    BinStr a;
    BinStr b;
    a += b;
}
