//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

class Solution {
public:
    int findComplement(int num) {
        int bit_place = 0;
        int ans = 0;
        
        while(num) {
            int xor_val = (num & 1);
            if(xor_val == 0) {
                ans += pow(2, bit_place);
            }
            bit_place++;
            num = num >> 1;
        }
        
        return ans;
    }
};