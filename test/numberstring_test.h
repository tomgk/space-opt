#ifndef NUMBERSTRING_TEST_H
#define NUMBERSTRING_TEST_H

#include<cstring>
#include<iostream>
#include<sstream>
#include "base.h"

template<typename T>
static void testN(const char *str)
{
    const T d(str);

    size_t len = strlen(str);
    size_t dSize = d.size();
    size_t ccap = d.concat_capacity();

    std::cout << "INPUT: \"" << str << "\" (len = " << len << ")" << std::endl;
    std::cout << "size: " << dSize << std::endl;
    std::cout << "ccap: " << ccap << std::endl;
    std::cout << "val:  \"" << d.str() << "\"" << std::endl;
    std::stringstream out;
    out << d;
    std::cout << "valo: \"" << out.str() << "\"" << std::endl;

    ASSERT_EQ(str, d.str());
    ASSERT_EQ(str, out.str());
    ASSERT_EQ(len, dSize);

    for(size_t i=0;i<len;++i)
        ASSERT_EQ(str[i], d.at(i));
}

#endif // NUMBERSTRING_TEST_H
