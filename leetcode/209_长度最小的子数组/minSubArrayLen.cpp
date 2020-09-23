class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int len = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= s){
                len = len == 0 ? j - i + 1 : min(len, j - i + 1);
                sum -= nums[i++];
            }
        }

        return len;
    }
};
