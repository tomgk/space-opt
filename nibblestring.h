#ifndef NIBBLESTRING_H
#define NIBBLESTRING_H

#include<vector>
#include<string>
#include<cstring>
#include<iostream>

template<typename T>
concept Charset = requires(T a)
{
    requires requires (const char *str, size_t index) {
        {T::getCharValue(str, index)} -> std::same_as<int>;
    };

    requires requires (int value) {
        {T::toChar(value)} -> std::same_as<char>;
    };
};

template<Charset Charset>
class NibbleString
{
    std::vector<char> m_values;
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

    NibbleString(const char *str)
    {
        size_t len = strlen(str);
        m_values.reserve(len*2+len%2);

        size_t cappedLen = len / 2 * 2;

        for(size_t i = 0; i < cappedLen; i+=2)
        {
            int n1 = Charset::getCharValue(str, i);
            int n2 = Charset::getCharValue(str, i+1);

            int v = to_hibit(n1) | to_lobit(n2);
            m_values.push_back(v);
        }

        //uneven digit count -> handle last digit
        if(len % 2 != 0)
        {
            m_unevenCount = true;

            int n1 = Charset::getCharValue(str, len-1);

            int v = to_hibit(n1) | to_lobit(0);
            m_values.push_back(v);
        }
        else
            m_unevenCount = false;
    }

    void add(char c)
    {
        char arr[]{c, '\0'};
        int val = Charset::getCharValue(arr, 0);

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

    size_t capacity()
    {
        return m_values.capacity();
    }

private:
    char access(size_t v_index, bool hi) const
    {
        char val = m_values.at(v_index);

        int v = (hi ? val >> 4 : val) & 0xF;

        //std::cout << "[" << v_index << "/" << (hi ? "hi" : "lo") << "] ";
        //std::cout << "= " << v << std::endl;

        return Charset::toChar(v);
    }
public:
    char at(size_t index) const
    {
        size_t v_index = index/2;
        bool hi = index % 2 == 0;
        return access(v_index, hi);
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

template<typename Charset>
inline std::ostream& operator<<(std::ostream &os, const NibbleString<Charset> &str)
{
    str.write(os);
    return os;
}

#endif // NIBBLESTRING_H
