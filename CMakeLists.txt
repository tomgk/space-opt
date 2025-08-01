cmake_minimum_required(VERSION 3.31)
project(space-opt)

set (CMAKE_CXX_STANDARD 20)

add_executable(space-opt
    nonzero.cpp
    excludevalue.h excludevalue.cpp
    optional.h optional.cpp
    nonnullptr.h nonnullptr.cpp

    nibblestring.h nibblestring.cpp
    flexcharset.h flexcharset.cpp
    numberstring.h numberstring.cpp
    floatstring.h floatstring.cpp

    numberstring_main.cpp
)
