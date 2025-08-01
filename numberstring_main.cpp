#include "numberstring.h"

#include "flexcharset.h"

#include "floatstring.h"

#include<sstream>

#define ASSERT_EQ(a, b) assertEq(__FILE__, __LINE__, #a, #b, a, b)

namespace std
{
std::string to_string(const char *str)
{
    return str;
}
std::string to_string(std::string str)
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

void mainFlex()
{
    using F = NibbleString<FlexCharset<' ', '!', 'd', 'e', 'h', 'l', 'o', 'r', 'w'>>;

    testN<F>("hello world!");
}

void NibbleStringAdd()
{
    DecimalString a("");
    ASSERT_EQ("", a.str());
    ASSERT_EQ(false, a.isUnevenCount());

    a += '1';
    ASSERT_EQ(true, a.isUnevenCount());
    ASSERT_EQ("1", a.str());

    a += '2';
    ASSERT_EQ("12", a.str());

    a += '3';
    ASSERT_EQ("123", a.str());

    a += '4';
    ASSERT_EQ("1234", a.str());

    a += '5';
    ASSERT_EQ("12345", a.str());
}

void testFloat(const char *str)
{
    testN<FloatDecimalString>(str);
}

void FloatDecimalTest()
{
    testFloat("123.45");
    testFloat("12345");
    testFloat(".45");
    testFloat("123.");
    testFloat(".");
    testFloat("");
}

int main()
{
    main10();
    std::cout << "------" << std::endl;
    main16();
    std::cout << "------" << std::endl;
    mainFlex();
    std::cout << "------" << std::endl;
    NibbleStringAdd();

    FloatDecimalTest();
}
