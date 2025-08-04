#include "testnumberstring.h"

#include<iostream>
#include<windows.h>

LONG handleError(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
    std::terminate();
    std::cerr << "ERROR" << std::endl;
    exit(255);
    return EXCEPTION_CONTINUE_SEARCH;
}

int main()
{
    //AddVectoredContinueHandler(1, handleError);

    main10();
    separator();
    main16();
    separator();
    mainFlex();
    separator();

    FloatDecimalTest();

    FixLengthFloatDecimalTest();

    BinaryTest();

    IntegerNibbleStringAdd();
    FloatNibbleStringAdd();

    std::cout << "SUCESS" << std::endl;
}
