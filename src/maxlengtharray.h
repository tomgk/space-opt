#ifndef MAXLENGTHARRAY_H
#define MAXLENGTHARRAY_H

#include<stdexcept>

template<typename T, size_t maxsize>
class MaxLengthArray
{
    T m_data[maxsize];
    size_t m_size;
public:
    MaxLengthArray():
        m_size(0){}

private:

    [[noreturn]] void outofmemory()
    {
        throw std::invalid_argument("out of memory");
    }

public:
    void reserve(size_t cap)
    {
        if(cap > maxsize)
            outofmemory();
    }

    void push_back(T val)
    {
        if(m_size == maxsize)
            outofmemory();

        m_data[m_size] = val;
        ++m_size;
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return maxsize;
    }

    bool empty() const
    {
        return m_size == 0;
    }

    T &at(size_t index)
    {
        if(index < m_size)
            throw std::out_of_range("out of bounds");

        return m_data[index];
    }

    const T &at(size_t index) const
    {
        if(index < m_size)
            throw std::out_of_range("out of bounds");

        return m_data[index];
    }

    T &back()
    {
        return m_data[m_size-1];
    }

    const T &back() const
    {
        return m_data[m_size-1];
    }
};

#endif // MAXLENGTHARRAY_H
