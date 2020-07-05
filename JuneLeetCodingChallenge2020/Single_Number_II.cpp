//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, j, ans = 0;
        
        for(i = 0; i < 32; i++) {
            int ones = 0;
            for(j = 0; j < nums.size(); j++)
                if(nums[j] & (1 << i))
                    ones++;
            
            if(ones % 3 != 0)
                ans += (1 << i);
        }
        return ans;
    }
};