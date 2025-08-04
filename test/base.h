#ifndef BASE_H
#define BASE_H

#include<stdexcept>

#define ASSERT_EQ(a, b) assertEq(__FILE__, __LINE__, #a, #b, a, b)
#define FAIL(str) throw std::invalid_argument(str)

namespace std
{
inline std::string to_string(const char *str)
{
    return str;
}
inline std::string to_string(std::string str)
{
    return str;
}
}

template<typename A, typename B>
static void assertEq(const char *file, long line, const char *varA, const char *varB, A a, B b)
{
    if(a != b)
        throw std::invalid_argument("file:///"+std::string(file)+":"+std::to_string(line)+" - expected "+std::to_string(a)+" but got "+std::to_string(b));
}

#endif // BASE_H
