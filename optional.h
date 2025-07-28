#ifndef OPTIONAL_H
#define OPTIONAL_H

#include "excludevalue.h"

template<typename T>
class Optional;

template<typename T, T excluded>
class Optional<ExcludeValue<T, excluded>>
{
    T m_value = 0;
    using value = ExcludeValue<T, excluded>;
public:
    Optional() = default;
    Optional(T val): m_value(val)
    {
        if(val == excluded)
            throw ExludedValueException("invalid value");
    }

    Optional& operator=(T val)
    {
        if(val == excluded)
            throw ExludedValueException("invalid value");

        m_value = val;
        return *this;
    }

    operator bool() const
    {
        return m_value != 0;
    }

    bool operator!() const
    {
        return m_value == 0;
    }

    bool operator==(Optional<value> value)
    {
        return m_value == value.m_value;
    }

    template<typename C>
    void ifPresent(C callback)
    {
        if(m_value)
            callback(NonZero(m_value));
    }

    value operator*() const
    {
        checkNonNull(m_value, "value absent");
        return m_value;
    }
};

#endif // OPTIONAL_H
