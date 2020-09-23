#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(){
    pair<string, int> p;
    typedef vector<pair<string, int>> VP;
    VP vp;

    //Linux系统下按Ctrl + D停止输入
    while(cin >> p.first >> p.second){
        vp.push_back(make_pair(p.first, p.second));
    }

    VP::iterator it;
    for(it = vp.begin(); it != vp.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
