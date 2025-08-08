#include "testnumberstring.h"

#include "flexcharset.h"

#include "floatstring.h"

#include "integerstring.h"

#include "separatortest.h"

#include "numberstring_test.h"

#include "base.h"

#include "binarystring.h"

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
void AppendTest(std::string input)
{
    S a("");
    ASSERT_EQ("", a.str());

    for(size_t i=0;i<input.size();++i)
    {
        ASSERT_EQ(input.substr(0, i), a.str());
        ASSERT_EQ(i, a.size());
        char c = input.at(i);
        a += c;
    }

    ASSERT_EQ(input, a.str());
}

void IntegerNibbleStringAdd()
{
    AppendTest<DecimalString>("12345");
    AppendTest<DecimalString>("");
    AppendTest<HexString>("CAFEBABE");
    AppendTest<HexString>("");
}

void FloatNibbleStringAdd()
{
    AppendTest<FloatDecimalString>("12345");
    AppendTest<FloatDecimalString>(".12345");
    AppendTest<FloatDecimalString>("12345.");
    AppendTest<FloatDecimalString>("");
    AppendTest<FloatHexString>("CAFE.BABE");
    AppendTest<FloatHexString>("");
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

#include "maxlengtharray.h"

template<size_t size>
void testFixLenFloat(const char *str)
{
    testN<FloatString<DigitCharset<10>, MaxLengthArray<char, size>>>(str);
}

void FixLengthFloatDecimalTest()
{
    testFixLenFloat<1>("");
    testFixLenFloat<1>("1");
    testFixLenFloat<10>("123");
    testFixLenFloat<10>("123.456");
    testFixLenFloat<10>(".456");
    testFixLenFloat<10>(".");

    testFixLenFloat<0>("");
}

void testBinary(const char *str)
{
    testN<BinaryString>(str);
}

void testBinaryFail(const char *str, const char *error)
{
    testNFailed<BinaryString>(str, error);
}

void BinaryTest()
{
    testBinary("");
    separator();
    testBinary("0");
    separator();
    testBinary("1");
    separator();
    testBinary("10011111011");
    separator();
    testBinaryFail("2", "Invalid value: 2");//Invalid value at index 0: 2 - full string is 2");
}
