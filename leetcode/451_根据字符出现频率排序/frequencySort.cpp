#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <typeinfo>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{  
    string s = "ttrAeeBeA";

    /*
    unordered_map<char, int> mymap;

    for(const auto &c : s){
        ++mymap[c];
    }
    */

    map<char, int> mymap;

    map<char, int>::iterator it;
    for(auto &x : s){
        it = mymap.find(x);
        if(it == mymap.end())
            mymap.insert( {x, 1} );
        else
            it->second++;
    }

    vector<pair<char, int>> vec;
    for(const auto &m : mymap){
        vec.push_back(m);
    }

    for(const auto &v : vec){
        cout << v.first << " : " << v.second << endl;
    }

    sort(vec.begin(), vec.end(), [](const pair<char, int> &p1, const pair<char, int> &p2) { 
        return p1.second > p2.second; 
    });

    string ret;
    for(const auto &v : vec){
        ret += string(v.second, v.first);
    }

    cout << ret << endl;

    return 0;
}
