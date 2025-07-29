#include "digitstring.h"

#include<cstring>

DigitString::DigitString(const char *str)
{
    size_t len = strlen(str);
    m_values.resize(len+len%2);
    for(size_t i = 0; i < len; ++i)
    {
        m_values.push_back(access(i, false));
        m_values.push_back(access(i, true));
    }
}
