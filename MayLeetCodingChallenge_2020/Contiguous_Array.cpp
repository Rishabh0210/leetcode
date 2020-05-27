//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i, sum = 0;
        int n = nums.size();
        unordered_map<int, int> preSum;
        int max_len = 0;
        for(i = 0; i < n; i++) {
            if(nums[i] == 0){
                nums[i] = -1;
            } 
            sum += nums[i];
            
            if(sum == 0) 
                max_len = i + 1;
            
            if(preSum.find(sum) != preSum.end()) 
                max_len = max(max_len, i - preSum[sum]);
            else 
                preSum[sum] = i;
        }
        return max_len;
    }
};