//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3381/

class Solution {
public:
    int hammingDistance(int x, int y) {
        long int comparator = 1;
        int i;
        int ans = 0;
        
        for(i = 0; i < 32; i++) {
            // cout << comparator << endl;
            int xIBit = (x & comparator) > 0 ? 1 : 0;
            int yIBit = (y & comparator) > 0 ? 1 : 0;
            
            if(xIBit != yIBit) 
                ans++;
            comparator = comparator << 1;
        }
        return ans;
    }
};