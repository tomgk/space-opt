#ifndef BINARYSTRING_H
#define BINARYSTRING_H

#include<vector>
#include<string>
#include<iostream>

class BinaryString
{
    std::vector<bool> data;
public:
    BinaryString(const char *str);
    int size() const;
    int size();
    int concat_capacity() const;
    char at(size_t index) const;
    std::string str() const;
};

inline std::ostream& operator<<(std::ostream &out, const BinaryString &str)
{
    out << str.str();
    return out;
}

#endif // BINARYSTRING_H
