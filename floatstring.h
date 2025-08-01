#ifndef FLOATSTRING_H
#define FLOATSTRING_H

#include "numberstring.h"

#include<numeric>

constexpr size_t NO_POINT = std::numeric_limits<size_t>::max();

template<typename Charset>
class FloatString
{
    NibbleString<Charset> m_digits;
    size_t m_pos;
    static constexpr char CHAR = '.';
public:
    FloatString(std::string_view str):
        m_digits(""), m_pos(NO_POINT)
    {
        size_t index = 0;
        for(char c : str)
        {
            if(c == CHAR)
            {
                if(m_pos != NO_POINT)
                    throw std::invalid_argument("double comma");

                m_pos = index;
            }
            else
                m_digits += c;

            ++index;
        }
    }

    size_t size() const
    {
        return m_digits.size() + (m_pos != NO_POINT ? 1 : 0);
    }

    std::string str() const
    {
        std::string s = m_digits.str();
        if(m_pos != NO_POINT)
            s.insert(m_pos, 1, CHAR);
        return s;
    }
};

using FloatDecimalString = FloatString<NumberCharset<10>>;
using FloatHexString = FloatString<NumberCharset<16>>;

template<typename Charset>
inline std::ostream& operator<<(std::ostream &os, const FloatString<Charset> &str)
{
    os << str.str();
    return os;
}

#endif // FLOATSTRING_H
