#include "String.hpp"

#if 1
String::Iterator String::begin() const{
    return m_data;
}

String::Iterator String::end() const{
    return m_data + m_size;
}
#endif


//构造函数
String::String() : m_size(0), 
                   m_capacity(15), 
                   m_data(new char[m_capacity])
{
    memset(m_data, 0, m_capacity);
}

String::String(const String& t) : m_size(0), 
                                  m_capacity(15), 
                                  m_data(new char[m_capacity])
{
    if(this == &t){
        return;
    }

    memset(m_data, 0, m_capacity);
    reserve(t.m_capacity);
    m_size = t.m_size;
    m_capacity = t.m_capacity;
    strncpy(m_data, t.m_data, m_size);
}

String::String(const char *t) : m_size(0),
                                m_capacity(15),
                                m_data(new char[m_capacity])
{
    if(t == nullptr){
        assert(false);
    }
    size_t size = strlen(t);
    reserve(size);
    m_size = size;
    strcpy(m_data, t);
}

String::String(size_t n, char c) : m_size(0),
                                   m_capacity(15),
                                   m_data(new char[m_capacity])
{
    reserve(n);
    m_size = n;
    memset(m_data, c, n);
}

String::String(const String& t, size_t n) : m_size(0),
                                            m_capacity(15),
                                            m_data(new char[m_capacity])
{
    reserve(n);
    m_size = n;
    strncpy(m_data, t.m_data, n);
}


//析构函数
String::~String(){
    if(m_data){
        delete[] m_data;
    }
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}


//基本功能
size_t String::size() const {
    return m_size;
}

bool String::empty() const {
    return m_size == 0;
}

void String::clear(){
    m_size = 0;
}

void String::push_back(const char c){
    reserve(m_size);
    m_data[m_size++] = c;
}

void String::pop_back(){
    if(m_size){
        --m_size;
    }
}

void String::reserve(size_t res_arg = 0){
    if(res_arg > m_capacity){
        m_capacity = (res_arg / m_capacity + 1) * 16 - 1;
        m_data = (char *)realloc(m_data, m_capacity);
        memset(m_data + m_size, 0, m_capacity);
    }
}


//重载运算符
String& String::operator=(const String& t){
    if(this == &t){
        return *this;
    }
    reserve(t.m_capacity);
    strcpy(m_data, t.m_data);
    m_size = t.m_size;
    return *this;
}

String& String::operator=(const char* s){
    if(s == nullptr){
        assert(false);
    }
    if(!strcmp(m_data, s)){
        return *this;
    }
    size_t size = strlen(s) + m_size;
    reserve(size);
    m_size = size;
    strcpy(m_data, s);
    return *this;
}

ostream& operator<<(ostream& os, const String& t){
    #if 1
    for(auto i : t){
        os << i;
    }
    #endif
    //os << t.m_data;

    return os;
}


