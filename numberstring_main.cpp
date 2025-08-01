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
    const T d(str);

    size_t len = strlen(str);
    size_t dSize = d.size();
    size_t ccap = d.concat_capacity();

    std::cout << "INPUT: \"" << str << "\" (len = " << len << ")" << std::endl;
    std::cout << "size: " << dSize << std::endl;
    std::cout << "ccap: " << ccap << std::endl;
    std::cout << "val:  \"" << d.str() << "\"" << std::endl;
    std::stringstream out;
    out << d;
    std::cout << "valo: \"" << out.str() << "\"" << std::endl;

    ASSERT_EQ(str, d.str());
    ASSERT_EQ(str, out.str());
    ASSERT_EQ(len, dSize);

    for(size_t i=0;i<len;++i)
        ASSERT_EQ(str[i], d.at(i));
}

static void separator()
{
    std::cout << "------" << std::endl;
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
    separator();
    test10("123456");
    separator();
    test10("");
    separator();
    test10("0");
}

void main16()
{
    test16("12ABCDEF");
    separator();
    test16("ACE");
    separator();
    test16("1A2C3E");
    separator();
    test16("123456");
    separator();
    test16("");
    separator();
    test16("0");
}

void mainFlex()
{
    using F = NibbleString<FlexCharset<' ', '!', 'd', 'e', 'h', 'l', 'o', 'r', 'w'>>;

    testN<F>("hello world!");
}

void NibbleStringAddTpl(std::string input)
{
    DecimalString a("");
    ASSERT_EQ("", a.str());

    for(size_t i=0;i<input.size();++i)
    {
        ASSERT_EQ(input.substr(0, i), a.str());
        a += input.at(i);
    }

    ASSERT_EQ(input, a.str());
}

void NibbleStringAdd()
{
    NibbleStringAddTpl("12345");
}

void testFloat(const char *str)
{
    testN<FloatDecimalString>(str);
}

void FloatDecimalTest()
{
    testFloat("123.45");
    separator();
    testFloat("12345");
    separator();
    testFloat(".45");
    separator();
    testFloat("123.");
    separator();
    testFloat(".");
    separator();
    testFloat("");
}

int main()
{
    main10();
    separator();
    main16();
    separator();
    mainFlex();
    separator();
    NibbleStringAdd();

    FloatDecimalTest();
}
