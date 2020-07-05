//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i, j;
        
        if(nums.size() <= 1) 
            return nums;
        
        vector<int> sub(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        
        int max_size = 1;
        int index = 0;
        for(i = 1; i < nums.size(); i++) {
            for(j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    if(sub[i] < sub[j] + 1) {
                        sub[i] = max(sub[i], sub[j] + 1);
                        prev[i] = j;   
                    }
                }
            }
            if(sub[i] > max_size) {
                max_size = sub[i];
                index = i;
            }
        }
        
        for(i = 0; i < nums.size(); i++)
            cout << prev[i] << " ";
        // cout << max_size << " " << index << endl;
        i = index;
        while(i >= 0) {
            ans.push_back(nums[i]);
            i = prev[i];
        }
        return ans;
    }
};