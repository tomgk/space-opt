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
    int size() const
    {
        return data.size();
    }
    int size()
    {
        return data.size();
    }

    int concat_capacity() const
    {
        return data.capacity();
    }

    char at(size_t index) const
    {
        return data.at(index) ? '1' : '0';
    }

    std::string str() const
    {
        std::string str;
        str.reserve(data.size());
        for(bool b : data)
            str += (b ? '1' : '0');
        return str;
    }
};

inline std::ostream& operator<<(std::ostream &out, const BinaryString &str)
{
    out << str.str();
    return out;
}

#endif // BINARYSTRING_H
