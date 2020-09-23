#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MyPrint(int val){
    cout << val << endl;
}

void test1(){
    vector<int> v;

    //插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //第一种
    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    while(itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++;
    }
    cout << endl;

    //第二种
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
    cout << endl;

    //第三种
    for_each(v.begin(), v.end(), MyPrint);
}

int main(){
    test1();

    return 0;
}
