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
    std::string str() const;
private:
    void write(std::ostream &out) const;
    friend std::ostream& operator<<(std::ostream &os, const DigitString &str);
};

inline std::ostream& operator<<(std::ostream &os, const DigitString &str)
{
    os << str.str();
    return os;
}

#endif // DIGITSTRING_H
