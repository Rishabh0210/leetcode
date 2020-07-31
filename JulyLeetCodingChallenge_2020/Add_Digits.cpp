//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3402/

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        return 1 + (num - 1)%9;
    }
};