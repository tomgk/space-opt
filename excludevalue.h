#ifndef EXCLUDEVALUE_H
#define EXCLUDEVALUE_H

#include<stdexcept>

template<typename T, T excluded>
class ExcludeValue
{
    T m_val;
public:
    constexpr static T EXCLUDED = excluded;

    ExcludeValue(T val): m_val(val)
    {
        if(val == excluded)
            throw std::exception();
    }
};

#endif // EXCLUDEVALUE_H
