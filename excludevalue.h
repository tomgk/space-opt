#ifndef EXCLUDEVALUE_H
#define EXCLUDEVALUE_H

#include<stdexcept>

class ExludedValueException : public std::invalid_argument
{
    void ctor()
    {
        ;
    }
public:
    ExludedValueException(const char *value):
        std::invalid_argument(value ? "invalid value "+std::string(value) : "nullptr")
    {
        ctor();
    }

    template<typename T>
    ExludedValueException(T value):
        std::invalid_argument("invalid value "+std::to_string(value))
    {
        ctor();
    }
};

/*
 * a type where one value is not valid,
 * a special version of this is NonNullPtr and NonZero
 */
template<typename T, T excluded>
class ExcludeValue
{
    T m_val;
public:
    constexpr static T EXCLUDED = excluded;

    ExcludeValue(T val): m_val(val)
    {
        if(val == excluded)
            throw ExludedValueException(val);
    }

    operator T() const
    {
        return m_val;
    }
};

#endif // EXCLUDEVALUE_H
