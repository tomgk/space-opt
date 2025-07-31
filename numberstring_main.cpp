#include "numberstring.h"

#include<sstream>

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
}

static void test10(const char *str)
{
    testN<DecimalString>(str);
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

static void test16(const char *str)
{
    testN<HexString>(str);
}

void main16()
{
    test16("12ABCDEF");
    if(0)
    {
    test16("ACE");
    test16("1A2C3E");
    std::cout << "------" << std::endl;
    test16("123456");
    std::cout << "------" << std::endl;
    test16("");
    std::cout << "------" << std::endl;
    test16("0");
    }
}

int main()
{
    main10();
    std::cout << "------" << std::endl;
    main16();
}
