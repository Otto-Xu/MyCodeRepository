class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            myset.insert(nums[i]);
        }
        
        return myset.size() != nums.size();
    }
};
