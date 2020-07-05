//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0, total = 0;
        while(n) {
            if(n - (i + 1) < 0)
                break;
            i++;
            n -= i;
        }
        return i;
    }
};
