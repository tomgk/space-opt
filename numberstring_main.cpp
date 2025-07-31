#include "numberstring.h"

#include<sstream>

static void test10(const char *str)
{
    DecimalString d(str);

    std::cout << "INPUT: \"" << str << "\" (len = " << strlen(str) << ")" << std::endl;
    std::cout << "size: " << d.size() << std::endl;
    std::cout << "val:  \"" << d.str() << "\"" << std::endl;
    std::stringstream out;
    out << d;
    std::cout << "valo: \"" << out.str() << "\"" << std::endl;
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
    HexString d(str);

    std::cout << "INPUT: \"" << str << "\" (len = " << strlen(str) << ")" << std::endl;
    std::cout << "size: " << d.size() << std::endl;
    std::cout << "val:  \"" << d.str() << "\"" << std::endl;
    std::stringstream out;
    out << d;
    std::cout << "valo: \"" << out.str() << "\"" << std::endl;
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
