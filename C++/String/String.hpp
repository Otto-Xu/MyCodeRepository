#include <iostream>
#include <string.h>
#include <cstring>
#include <cassert>

using namespace std;

class String{
    size_t m_capacity;
    char *m_data;
    size_t m_size;

public:
    //构造函数
    String();
    String(const String&);
    String(const char*);
    String(size_t, char);
    String(const String&, size_t);

    #if 1
    typedef char* Iterator;
    Iterator begin() const;
    Iterator end() const;
    #endif

    //析构函数
    ~String();
   
    //基本功能
    size_t size() const;
    bool empty() const;
    void clear();
    void push_back(const char c);
    void pop_back();
    //void resize(size_t n, const char c = ' ');    
    void reserve(size_t res_arg);

    //重载运算符“ = ”
    String& operator=(const String&);
    String& operator=(const char*);
    
    //重载 << 输出运算符
    friend ostream& operator<<(ostream& os, const String& t);
};
