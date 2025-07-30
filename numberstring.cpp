#include "numberstring.h"

#include<stdexcept>

int DecimalCharset::parseDigit(const char *str, size_t index)
{
    char ch = str[index];
    if(ch < '0' || ch >= '9')
        throw std::invalid_argument(std::string()+"invalid: "+str+" - digit DEC"+std::to_string(int(ch)));

    return ch - '0';
}

char DecimalCharset::toDigit(int value)
{
    return value + '0';
}


#include<sstream>

static void test(const char *str)
{
    DecimalString d(str);

    std::cout << "INPUT: \"" << str << "\" (len = " << strlen(str) << ")" << std::endl;
    std::cout << "size: " << d.size() << std::endl;
    std::cout << "val:  \"" << d.str() << "\"" << std::endl;
    std::stringstream out;
    out << d;
    std::cout << "valo: \"" << out.str() << "\"" << std::endl;
}

int main()
{
    test("123");
    std::cout << "------" << std::endl;
    test("123456");
    std::cout << "------" << std::endl;
    test("");
    std::cout << "------" << std::endl;
    test("0");
}
