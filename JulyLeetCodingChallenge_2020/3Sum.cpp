//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int i;
        for(i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            
            int start = i + 1;
            int end = nums.size() - 1;
            
            while(start < end) {
                int sum = nums[start] + nums[end];
                
                if(sum < target)    start++;
                else if(sum > target) end--;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    
                    ans.push_back(temp);
                    
                    while(start < nums.size() && nums[start] == temp[1]) start++;
                    while(end >= 0 && nums[end] == temp[2]) end--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};