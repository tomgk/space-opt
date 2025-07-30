#include "digitstring.h"

#include<cstring>
#include<stdexcept>

static int parseDigit(const char *str, size_t index)
{
    char ch = str[index];
    if(ch < '0' || ch >= '9')
        throw std::invalid_argument(std::string()+"invalid: "+str+" - digit DEC"+std::to_string(int(ch)));

    return ch - '0';
}

DigitString::DigitString(const char *str)
{
    size_t len = strlen(str);
    m_values.reserve(len*2+len%2);

    size_t cappedLen = len / 2 * 2;

    for(size_t i = 0; i < cappedLen; i+=2)
    {
        int n1 = parseDigit(str, i);
        int n2 = parseDigit(str, i+1);

        int v = (n1 << 4) | n2;
        m_values.push_back(v);
    }

    //uneven digit count -> handle last digit
    if(len % 2 != 0)
    {
        m_unevenCount = true;

        int n1 = parseDigit(str, len-1);

        int v = (n1 << 4) | 0;
        m_values.push_back(v);
    }
    else
        m_unevenCount = false;
}

char DigitString::access(size_t v_index, bool hi) const
{
    char val = m_values.at(v_index);

    int v = hi ? val >> 4 : val & 0xF;
    return v + '0';
}

char DigitString::at(size_t index) const
{
    size_t v_index = index/2;
    bool hi = index % 2 == 0;
    return access(v_index, hi);
}

size_t DigitString::size() const
{
    return m_values.size() * 2 - (m_unevenCount ? 1 : 0);
}

std::string DigitString::str()
{
    std::string str;
    size_t size = this->size();
    str.reserve(size);

    for(size_t i=0;i<size;++i)
        str += at(i);

    return str;
}

#include<iostream>

static void test(const char *str)
{
    DigitString d(str);

    std::cout << "size: " << d.size() << std::endl;
    std::cout << "val:  " << d.str() << std::endl;
}

int main()
{
    test("123");
    std::cout << "------" << std::endl;
    test("123456");
}
