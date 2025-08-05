#include "separatortest.h"

#include<iostream>

void separator()
{
    if(doOutput())
        std::cout << "------" << std::endl;
}

bool doOutput()
{
    return false;
}
