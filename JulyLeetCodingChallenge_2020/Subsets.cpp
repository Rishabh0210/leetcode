//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3387/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int totalSets = pow(2, nums.size());
        int i;
        vector<vector<int>> ans;
        
        for(i = 0; i < totalSets; i++) {
            vector<int> temp;
            for(int j = 0; j < nums.size(); j++) {
                int setBit = 1 << j;
                if(i & setBit)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};