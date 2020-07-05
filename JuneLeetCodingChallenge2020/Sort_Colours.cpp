//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/


class Solution {
private:
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int l, m, h, i;
        l = m = 0;
        h = nums.size() - 1;
        
        while(m <= h) {
            if(nums[m] == 0) {
               swap(nums, l++, m++); 
            } else if (nums[m] == 1) {
                m++;
            } else if (nums[m] == 2) {
                swap(nums, m, h--);
            }
        }
    }
};