cmake_minimum_required(VERSION 3.31)
project(space-opt)

set (CMAKE_CXX_STANDARD 20)

add_executable(space-opt
    src/nonzero.cpp
    src/excludevalue.h src/excludevalue.cpp
    src/optional.h src/optional.cpp
    src/nonnullptr.h src/nonnullptr.cpp

    src/nibblestring.h src/nibblestring.cpp
    src/flexcharset.h src/flexcharset.cpp
    src/numberstring.h src/numberstring.cpp
    src/floatstring.h src/floatstring.cpp

    numberstring_main.cpp
)
target_include_directories(space-opt PUBLIC src)
