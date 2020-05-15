//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = -1;
        
        while(low <= high) {
            mid = (low + high) / 2;
            
            if(low == high)
                break;
            
            if(mid % 2 == 1) {
                if(nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else if(nums[mid] == nums[mid + 1])
                    high = mid - 1;
                else
                    break;
            } else {
               if(nums[mid] == nums[mid - 1])
                    high = mid - 2;
                else if(nums[mid] == nums[mid + 1])
                    low = mid + 2;
                else
                    break; 
            }
        }
        return nums[mid];
    }
};