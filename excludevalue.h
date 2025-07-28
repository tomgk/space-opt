#ifndef EXCLUDEVALUE_H
#define EXCLUDEVALUE_H

#include<stdexcept>

class ExludedValueException : public std::invalid_argument
{
public:
    ExludedValueException(const char *msg): std::invalid_argument(msg){}
};

template<typename T, T excluded>
class ExcludeValue
{
    T m_val;
public:
    constexpr static T EXCLUDED = excluded;

    ExcludeValue(T val): m_val(val)
    {
        if(val == excluded)
            throw ExludedValueException("invalid value");
    }

    operator T() const
    {
        return m_val;
    }
};

#endif // EXCLUDEVALUE_H
