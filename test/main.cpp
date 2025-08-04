#include "testnumberstring.h"

#include<iostream>

int main()
{
    main10();
    separator();
    main16();
    separator();
    mainFlex();
    separator();

    FloatDecimalTest();

    FixLengthFloatDecimalTest();

    BinaryTest();

    NibbleStringAdd();

    std::cout << "SUCESS" << std::endl;
}
