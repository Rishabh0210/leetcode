//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        
        while(n) {
            if(n % 2 != 0 && n != 1)
                return false;
            n = n >> 1;
        }
        return true;
    }
};