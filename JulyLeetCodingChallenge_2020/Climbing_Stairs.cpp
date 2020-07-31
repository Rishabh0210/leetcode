//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3407/

class Solution {
public:
    int climbStairs(int n) {
        int DP[n + 1][3];
        int i, j;
        for(i = 0; i <= n; i++)
            for(j = 0; j < 3; j++) 
                DP[i][j] = 0;
        DP[0][0] = 1;
        DP[0][1] = 1;
        DP[0][2] = 1;
        
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= 2; j++){
                DP[i][j] = DP[i][j - 1];
                if(i >= j)
                    DP[i][j] += DP[i - j][2];
            }
        }
        return DP[n][2];
    }
};