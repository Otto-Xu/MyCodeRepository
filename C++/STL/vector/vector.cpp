#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;

    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }

    cout << endl;
    
    /*通过iterator找出vector下标*/
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << &*it - &v[0] << endl;
    }

    return 0;
}
