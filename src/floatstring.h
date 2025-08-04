#ifndef FLOATSTRING_H
#define FLOATSTRING_H

#include "integerstring.h"

#include<numeric>
#include<stdexcept>

constexpr size_t NO_POINT = std::numeric_limits<size_t>::max();

template<typename C>
class FloatString
{
    using S = NibbleString<C>;
    S m_digits;
    size_t m_pos;
    static constexpr char CHAR = '.';
public:
    FloatString(const S &digits):
        m_digits(digits), m_pos(NO_POINT)
    {

    }

    FloatString(const std::string_view str):
        m_digits(""), m_pos(NO_POINT)
    {
        bool hasDot = str.find(CHAR) != std::string_view::npos;
        m_digits.reserve(str.size() - (hasDot ? 1 : 0));

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

    FloatString &operator+=(char c)
    {
        if(c != CHAR)
            m_digits += c;
        //it is the dot
        else
        {
            if(m_pos != NO_POINT)
                throw std::invalid_argument("double dot");

            m_pos = m_digits.size();
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

    char at(size_t index) const
    {
        if(m_pos == NO_POINT)
            return m_digits.at(index);
        else
        {
            if(index < m_pos)
                return m_digits.at(index);
            else if(index == m_pos)
                return CHAR;
            else//if index > m_pos
                //minus one since dot isnt't included in m_digits
                return m_digits.at(index -1);
        }
    }

    void reserve(size_t size)
    {
        //prevent underflow by early exit
        if(size == 0)
            return;

        //if FloatString already contains a dot,
        //we definitely don't need to reserve space for it
        if(m_pos != NO_POINT)
            --size;

        m_digits.reserve(size);
    }

    //only applies for concat, not other operations
    size_t concat_capacity() const
    {
        //since it is concat_capacity, the dot won't be overriden
        return m_digits.concat_capacity() + (m_pos != NO_POINT ? 1 : 0);
    }

//private:
    void write(std::ostream &out) const
    {
        size_t size = this->size();

        for(size_t i=0;i<size;++i)
            out.put(at(i));
    }

    //friend std::ostream& operator<< <Charset>(std::ostream &os, const FloatString<Charset> &str);
};

using FloatDecimalString = FloatString<DigitCharset<10>>;
using FloatHexString = FloatString<DigitCharset<16>>;

template<typename Charset>
inline std::ostream& operator<<(std::ostream &os, const FloatString<Charset> &str)
{
    str.write(os);
    //os << str.str();
    return os;
}

#endif // FLOATSTRING_H
