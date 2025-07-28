#ifndef NONZERO_H
#define NONZERO_H

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

template<typename T>
using NonZero = ExcludeValue<T, 0>;

template<typename T>
class Optional;

template<typename T, T excluded>
class Optional<ExcludeValue<T, excluded>>
{
    T m_value = 0;
public:
    Optional() = default;
    Optional(T val): m_value(val)
    {
        if(val == excluded)
            throw std::exception();
    }

    Optional& operator=(T val)
    {
        if(val == excluded)
            throw std::exception();

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

    bool operator==(Optional<ExcludeValue<T, excluded>> value)
    {
        return m_value == value.m_value;
    }

    template<typename C>
    void ifPresent(C callback)
    {
        if(m_value)
            callback(NonZero(m_value));
    }

    NonZero<T> get()
    {
        checkNonNull(m_value, "value absent");
        return m_value;
    }
};

static_assert(sizeof(int) == sizeof(Optional<NonZero<int>>));

Optional<NonZero<int>> get()
{
    Optional<NonZero<int>> a;
    Optional<NonZero<int>> b;

    int x = a < b;

    return {x};
}

#endif // NONZERO_H
