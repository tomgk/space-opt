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
        return m_value != value::EXCLUDED;
    }

    bool operator!() const
    {
        return m_value == value::EXCLUDED;
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

const char *EMPTY_STRING_VIEW();

template<>
class Optional<std::string_view>
{
    std::string_view m_value;
    bool isEmpty() const
    {
        return m_value.data() == EMPTY_STRING_VIEW();
    }
public:
    Optional(): m_value(EMPTY_STRING_VIEW()){}
    Optional(std::string_view value): m_value(value){}

    operator bool() const
    {
        return !isEmpty();
    }

    bool operator!() const
    {
        return isEmpty();
    }

    bool operator==(Optional<std::string_view> value)
    {
        bool a = isEmpty();
        bool b = value.isEmpty();

        //both => same
        if(a == b)
            return true;
        //either but not both => different
        else if(a || b)
            return false;

        return m_value == value.m_value;
    }

    template<typename C>
    void ifPresent(C callback)
    {
        if(isEmpty())
            callback(m_value);
    }

    std::string_view operator*() const
    {
        if(isEmpty())
            throw std::invalid_argument("Optional<std::string_view>::* - not set");

        return m_value;
    }
};

#endif // OPTIONAL_H
