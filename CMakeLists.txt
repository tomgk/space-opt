cmake_minimum_required(VERSION 3.31)
project(sample-transform)

set (CMAKE_CXX_STANDARD 20)

add_executable(space-opt
    nonzero.cpp
    excludevalue.h excludevalue.cpp
    optional.h optional.cpp
    nonnullptr.h nonnullptr.cpp
    numberstring.h numberstring.cpp
    nibblestring.h nibblestring.cpp
    numberstring_main.cpp
    flexcharset.h flexcharset.cpp
)
