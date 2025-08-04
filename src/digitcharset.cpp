#include "digitcharset.h"

std::invalid_argument raiseInvalid(char ch)
{
    return std::invalid_argument(std::string("invalid: DEC"+std::to_string(int(ch))));
}
