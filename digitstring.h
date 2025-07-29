#ifndef DIGITSTRING_H
#define DIGITSTRING_H

#include<vector>
#include<string>

class DigitString
{
    std::vector<char> m_values;
public:
    DigitString(const char *str);

private:
    char access(size_t v_index, bool offset) const
    {
        char val = m_values.at(v_index);

        int v = offset ? val >> 4 : val & 0xF;
        return v + '0';
    }
public:
    char at(size_t index) const
    {
        size_t v_index = index/2;
        bool offset = index % 2;
        return access(v_index, offset);
    }

    size_t size() const
    {
        return m_values.size() * 2;
    }

    std::string str()
    {
        std::string str;

        for(size_t i=0;i<size();++i)
            str += at(i);

        return str;
    }
};

#endif // DIGITSTRING_H
