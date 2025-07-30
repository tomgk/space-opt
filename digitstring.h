#ifndef DIGITSTRING_H
#define DIGITSTRING_H

#include<vector>
#include<string>

class DigitString
{
    std::vector<char> m_values;
    bool m_unevenCount;
public:
    DigitString(const char *str);
private:
    char access(size_t v_index, bool hi) const;
public:
    char at(size_t index) const;
    size_t size() const;
    std::string str();
};

#endif // DIGITSTRING_H
