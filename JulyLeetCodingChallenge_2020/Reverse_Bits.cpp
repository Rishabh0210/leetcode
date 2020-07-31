//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3388/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // cout << n;
        uint32_t ans = 0;
        int i;
        for(i = 0; i < 32; i++) {
            if(n & (1 << i)) {
                ans += pow(2, 31 - i);
            }
        }
        return ans;
    }
};