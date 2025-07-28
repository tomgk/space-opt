#include "nonzero.h"

#include<iostream>

int main()
{
    Optional<NonZero<int>> v(3);

    std::cout << v << std::endl;

    v = 0;

    std::cout << v << std::endl;
}
