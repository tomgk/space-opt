#include "nonzero.h"

#include<iostream>

#include "optional.h"

#include "integerstring.h"

static_assert(sizeof(int) == sizeof(Optional<NonZero<int>>));

Optional<NonZero<int>> get()
{
    Optional<NonZero<int>> a;
    Optional<NonZero<int>> b;

    int x = a < b;

    return {x};
}

int mainx()
{
    Optional<NonZero<int>> v(3);

    std::cout << v << std::endl;

    v = 0;

    std::cout << v << std::endl;

    return 0;
}
