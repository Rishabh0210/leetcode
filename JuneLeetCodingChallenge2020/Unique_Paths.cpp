//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3375/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, 0));
        int i, j;
        
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(i == 0 || j == 0)
                    DP[i][j] = 1;
                else
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }
        
        return DP[m - 1][n - 1];
    }
};