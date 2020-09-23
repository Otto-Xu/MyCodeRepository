class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mymap;
        for(int i = 0; i < arr.size(); i++){
            mymap.insert( {arr[i], i} );
        }

        int i = 1;
        /*
        为什么这段代码执行了结果就会出错，似乎是beg仅在{}里面有效而已，改动后map还是没变
        for(auto beg : mymap){
            beg.second = i++;
        }
        */
        for(auto beg = mymap.begin(); beg != mymap.end(); beg++){
            (*beg).second = i++;
        }

        vector<int> returnarr;
        for(auto k : arr){
            returnarr.push_back(mymap[k]);
        }
        /*
        for(int k = 0; k < arr.size(); k++){
            returnarr.push_back(mymap[arr[k]]);
        }
        */

        return returnarr;
    }
};
