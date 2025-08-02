#include "numberstring.h"

#include "flexcharset.h"

#include "floatstring.h"

#include "numberstring_test.h"

#include "base.h"

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

template<typename S>
void NibbleStringAddTpl(std::string input)
{
    S a("");
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
    NibbleStringAddTpl<DecimalString>("12345");
    NibbleStringAddTpl<DecimalString>("");
    NibbleStringAddTpl<HexString>("CAFEBABE");
    NibbleStringAddTpl<HexString>("");
    NibbleStringAddTpl<FloatDecimalString>("12345");
    NibbleStringAddTpl<FloatDecimalString>(".12345");
    NibbleStringAddTpl<FloatDecimalString>("12345.");
    NibbleStringAddTpl<FloatHexString>("CAFE.BABE");
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
