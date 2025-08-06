#ifndef BINARYSTRING_H
#define BINARYSTRING_H

#include<vector>
#include<string>
#include<iostream>

template<typename Collection = std::vector<bool>, char F = '0', char T = '1'>
class BasicBinaryString
{
    Collection data;

    static bool toBool(char ch);
    static char toChar(bool b);

    static constexpr char FALSE = F;
    static constexpr char TRUE = T;

public:
    BasicBinaryString(const char *str);
    int size() const;
    int size();
    int concat_capacity() const;
    char at(size_t index) const;
    std::string str() const;
    BasicBinaryString &operator+=(char c);

private:
    void write(std::ostream &out) const;

public:
    friend inline std::ostream& operator<<(std::ostream &out, const BasicBinaryString &str)
    {
        str.write(out);
        return out;
    }
};

using BinaryString = BasicBinaryString<>;


#endif // BINARYSTRING_H
