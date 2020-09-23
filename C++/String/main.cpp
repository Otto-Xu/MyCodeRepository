#include "String.hpp"

void test1(){
    cout << "------test1()------" << endl;
    String s1;
    s1 = "bcd";
    
    String s2;
    s2 = "abcdefghijklmnopq";

    String s3("xyz");
    String s4(s2);
    String s5(5, 'z');

    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << "s4:" << s4 << endl;
    cout << "s5:" << s5 << endl;
}

void test2(){
    cout << "------test2()------" << endl;
    
    String s1;
    s1 = "abcdef";

    cout << "s1.size:" << s1.size() << endl;
    cout << "s1.empty:" << s1.empty() << endl;

    s1.pop_back();
    cout << "s1:" << s1 << endl;
    s1.push_back('h');
    cout << "s1:" << s1 << endl;

    s1.clear();
    cout << "s1:" << s1 << endl;
    cout << "s1.empty:" << s1.empty() << endl;
}

int main() {
    
    test1();
    test2();

    return 0;
}
