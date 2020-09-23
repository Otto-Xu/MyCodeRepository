class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m.insert({nums[i], i});
        }
        for(auto beg = m.begin(), end = --m.end(); beg != end;){
            if((*beg).first + (*end).first == target)
                return {(*beg).second, (*end).second};
            else if((*beg).first + (*end).first > target)
                end--;
            else
                beg++;
        }
        return {};
    }
};
