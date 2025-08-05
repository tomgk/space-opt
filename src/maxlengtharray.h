#ifndef MAXLENGTHARRAY_H
#define MAXLENGTHARRAY_H

#include<stdexcept>

template<typename T, size_t maxsize>
class MaxLengthArray
{
    static constexpr size_t ENTRY_SIZE = sizeof(T);
    char m_rdata[ENTRY_SIZE + maxsize];
    size_t m_size;
public:
    MaxLengthArray():
        m_size(0){}

private:
    void* rentry(size_t index)
    {
        return m_rdata + ENTRY_SIZE * index;
    }

    const T* entry(size_t index) const
    {
        return reinterpret_cast<T*>(const_cast<MaxLengthArray*>(this)->rentry(index));
    }

    T* entry(size_t index)
    {
        return reinterpret_cast<T*>(rentry(index));
    }

    [[noreturn]] void outofmemory(size_t required)
    {
        throw std::invalid_argument(
            "out of memory, "
            "max="+std::to_string(maxsize)+", "
            "required "+std::to_string(required));
    }

public:
    void reserve(size_t cap)
    {
        if(cap > maxsize)
            outofmemory(cap);
    }

    void push_back(T val)
    {
        if(m_size == maxsize)
            outofmemory(m_size+1);

        new(rentry(m_size))T(val);
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
        if(index >= m_size)
            throw std::out_of_range("out of bounds");

        return *entry(index);
    }

    const T &at(size_t index) const
    {
        if(index >= m_size)
            throw std::out_of_range("out of bounds");

        return *entry(index);
    }

    T &back()
    {
        return *entry(m_size-1);
    }

    const T &back() const
    {
        return *entry(m_size-1);
    }

    ~MaxLengthArray()
    {
        for(size_t i = 0; i < m_size; ++i)
            entry(i)->~T();
    }
};

#endif // MAXLENGTHARRAY_H
