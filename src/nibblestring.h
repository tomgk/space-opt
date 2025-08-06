#ifndef NIBBLESTRING_H
#define NIBBLESTRING_H

#include<vector>
#include<string>
#include<cstring>
#include<iostream>

template<typename T>
concept NibbleCharset = requires(T a)
{
    //takes ch and returns the value in the charset
    requires requires (char ch) {
        {T::getCharValue(ch)} -> std::same_as<int>;
    };

    //turns a charset value and retursn
    requires requires (int value) {
        {T::toChar(value)} -> std::same_as<char>;
    };

    requires T::bitsize <= 4;
};

template<NibbleCharset Charset, typename Collection = std::vector<char>>
class NibbleString
{
    Collection m_values;
    bool m_unevenCount;

    static void checkVal(int val)
    {
        if(val < 0 || val > 16)
            throw std::invalid_argument("out of bounds");
    }

    static int to_hibit(int val)
    {
        checkVal(val);
        return val << 4;
    }

    static int to_lobit(int val)
    {
        checkVal(val);
        return val;
    }
public:
    bool isUnevenCount() const
    {
        return m_unevenCount;
    }

    NibbleString():
        m_unevenCount(false)
    {

    }

    NibbleString(const std::string_view str)
    {
        size_t len = str.size();
        m_values.reserve(len*2+len%2);

        size_t cappedLen = len / 2 * 2;

        for(size_t i = 0; i < cappedLen; i+=2)
        {
            int n1 = Charset::getCharValue(str.at(i));
            int n2 = Charset::getCharValue(str.at(i+1));

            int v = to_hibit(n1) | to_lobit(n2);
            m_values.push_back(v);
        }

        //uneven digit count -> handle last digit
        if(len % 2 != 0)
        {
            m_unevenCount = true;

            int n1 = Charset::getCharValue(str.at(len-1));

            int v = to_hibit(n1) | to_lobit(0);
            m_values.push_back(v);
        }
        else
            m_unevenCount = false;
    }

    void add(char c)
    {
        int val = Charset::getCharValue(c);

        if(m_values.empty())
        {
            //std::cout << "ADD: start new string" << std::endl;
            m_values.push_back(to_hibit(val));
            m_unevenCount = true;
            return;
        }

        //uneven -> last nibble is still unfilled
        if(m_unevenCount)
        {
            //std::cout << "ADD: add to uneven" << std::endl;
            m_values.back() |= to_lobit(val);
            //mark it as filled
            m_unevenCount = false;
        }
        //even -> need a new byte
        else
        {
            //std::cout << "ADD: add new char" << std::endl;
            //since we start a new byte, it is the high val
            m_values.push_back(to_hibit(val));
            //and since the lobit isn't used yet, mark it as such
            m_unevenCount = true;
        }
    }

    NibbleString operator+=(char c)
    {
        add(c);
        return *this;
    }

    void reserve(size_t size)
    {
        //reserve the number of bytes needed for that many nibbles
        m_values.reserve(size / 2 + size % 2);
    }

    //only applies for concat, not other operations
    size_t concat_capacity() const
    {
        return m_values.capacity() * 2;
    }

private:
    static int accessNibble(char val, bool hi)
    {
        return (hi ? val >> 4 : val) & 0xF;
    }

    char access(size_t v_index, bool hi) const
    {
        char val = m_values.at(v_index);

        int v = accessNibble(val, hi);

        //std::cout << "[" << v_index << "/" << (hi ? "hi" : "lo") << "] ";
        //std::cout << "= " << v << std::endl;

        return Charset::toChar(v);
    }
public:
    template<typename PTR>
    class reference
    {
        PTR m_ptr;
        bool m_hi;

        void dump() const
        {
            //std::cout << "reference@" << (const void*)m_ptr << " = " << std::hex << (int)*m_ptr << " hi=" << m_hi << std::endl;
        }

    public:
        reference(PTR ptr, bool hi): m_ptr(ptr), m_hi(hi)
        {
            dump();
        }

        operator char() const
        {
            dump();
            int v = accessNibble(*m_ptr, m_hi);
            //std::cout << " --> " << v << std::endl;
            return Charset::toChar(v);
        }
    };

private:
template<typename Ref, typename NS>
    static Ref constructReference(NS& string, size_t index)
    {
        return {&string.m_values.at(index/2), index % 2 == 0};
    }
public:

    reference<char*> at(size_t index)
    {
        return constructReference<reference<char*>>(*this, index);
    }

    reference<const char*> at(size_t index) const
    {
        return constructReference<reference<const char*>>(*this, index);
    }

    size_t size() const
    {
        return m_values.size() * 2 - (m_unevenCount ? 1 : 0);
    }

    std::string str() const
    {
        std::string str;
        size_t size = this->size();
        str.reserve(size);

        for(size_t i=0;i<size;++i)
            str += at(i);

        return str;
    }

private:
    void write(std::ostream &out) const
    {
        size_t size = this->size();

        for(size_t i=0;i<size;++i)
            out.put(at(i));
    }

    friend std::ostream& operator<< <Charset>(std::ostream &os, const NibbleString<Charset> &str);
};

template<typename Charset, typename Collection>
inline std::ostream& operator<<(std::ostream &os, const NibbleString<Charset, Collection> &str)
{
    str.write(os);
    return os;
}

#endif // NIBBLESTRING_H
