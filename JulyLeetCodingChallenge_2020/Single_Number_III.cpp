//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        int i;
        
        for(i = 0; i < nums.size(); i++)
            bitmask ^= nums[i];
        
        int diff = bitmask & (-bitmask);
        int x = 0;
        for(i = 0; i < nums.size(); i++) {
            if((diff & nums[i]) != 0) {
                x ^= nums[i];
            }
        }
        
        int y = bitmask ^ x;
        vector<int> ans = {x, y};
        
        return ans;
    }
};