#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <typeinfo>

using namespace std;

int main()
{   
    //定义简单的lambda表达式
    auto basiclambda = []{cout << "hello, world" << endl;};
    //调用
    basiclambda();//输出：hello, world


    //指明返回类型
    auto add = [](int a, int b) -> int {return a + b;};
    //自动推断返回类型
    auto multiply = [](int a, int b){return a * b;};
    cout << add(2, 5) << "  " << multiply(2,5) << endl;;  //输出：7  10


    int  x = 10;
    //复制捕捉局部变量x，无法修改该变量
    auto add_x = [x](int a){
        //x  *= 2; x为只读变量
        return a + x;
    };
    //引用捕捉局部变量x，可以修改该变量
    auto multiply_x = [&x](int a){
        x *= 2;
        return a * x;
    };
    cout << add_x(10) << "  " << multiply_x(10) << endl; //输出：20  200


    //复制捕获局部变量x，可以修改该变量
    auto add_modify_x = [x](int a) mutable {x *= 2; return a + x;};
    cout << add_modify_x(10) << endl;  //输出：50

    return 0;
}
