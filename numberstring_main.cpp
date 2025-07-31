#include "numberstring.h"

#include<sstream>

#define ASSERT_EQ(a, b) assertEq(#a, #b, a, b)

template<typename A, typename B>
static void assertEq(const char *varA, const char *varB, A a, B b)
{
    if(a != b)
        throw std::invalid_argument("different");
}

template<typename T>
static void testN(const char *str)
{
    T d(str);

    std::cout << "INPUT: \"" << str << "\" (len = " << strlen(str) << ")" << std::endl;
    std::cout << "size: " << d.size() << std::endl;
    std::cout << "val:  \"" << d.str() << "\"" << std::endl;
    std::stringstream out;
    out << d;
    std::cout << "valo: \"" << out.str() << "\"" << std::endl;

    ASSERT_EQ(str, d.str());
    ASSERT_EQ(str, out.str());
    ASSERT_EQ(strlen(str), d.size());
}

static void test10(const char *str)
{
    testN<DecimalString>(str);
}

static void test16(const char *str)
{
    testN<HexString>(str);
}

void main10()
{
    test10("123");
    std::cout << "------" << std::endl;
    test10("123456");
    std::cout << "------" << std::endl;
    test10("");
    std::cout << "------" << std::endl;
    test10("0");
}

void main16()
{
    test16("12ABCDEF");
    std::cout << "------" << std::endl;
    test16("ACE");
    std::cout << "------" << std::endl;
    test16("1A2C3E");
    std::cout << "------" << std::endl;
    test16("123456");
    std::cout << "------" << std::endl;
    test16("");
    std::cout << "------" << std::endl;
    test16("0");
}

int main()
{
    main10();
    std::cout << "------" << std::endl;
    main16();
}
