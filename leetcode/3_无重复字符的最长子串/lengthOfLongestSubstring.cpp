class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();
        
        int len = 1;
        int max = 1;
        string new_s(1, s[0]);

        for(int i = 1; i < s.size(); i++){
            new_s += s[i];
            len++;
            if(1 == count(new_s.begin(), new_s.end(), s[i])){
                max = max > len ? max : len;
            } else {
                while(1 != count(new_s.begin(), new_s.end(), s[i])){
                    new_s.erase(new_s.begin());
                    len--;
                }
            }
        }

        return max;
    }
};
