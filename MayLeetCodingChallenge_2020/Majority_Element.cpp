//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i;
        unordered_map<int, int> count;
        
        for(i = 0; i < nums.size(); i++){
            if(count.find(nums[i]) == count.end())
                count[nums[i]] = 1;
            else
                count[nums[i]]++;
        }
        int ans = 0;
        for(auto it : count) {
            if(it.second > (nums.size()/2)) {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};