#ifndef FLEXCHARSET_H
#define FLEXCHARSET_H

#include<stdexcept>
#include<algorithm>

template<char...chs>
class FlexCharset
{
    constexpr static char VALUES[] = {chs...};
    constexpr static size_t COUNT = sizeof...(chs);
    static_assert(COUNT > 2);
    static_assert(COUNT <= 16);
public:
    static int getCharValue(char ch)
    {
        auto iter = std::find(std::begin(VALUES), std::end(VALUES), ch);
        if(iter == std::end(VALUES))
            throw std::invalid_argument("invalid character");

        return iter - std::begin(VALUES);
    }

    static char toChar(int value)
    {
        if(value >= COUNT)
            throw std::invalid_argument("too hight: "+std::to_string(value));

        return VALUES[value];
    }
};

#endif // FLEXCHARSET_H
