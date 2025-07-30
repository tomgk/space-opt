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

int main()
{
    test10("123");
    std::cout << "------" << std::endl;
    test10("123456");
    std::cout << "------" << std::endl;
    test10("");
    std::cout << "------" << std::endl;
    test10("0");
}
