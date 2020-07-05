//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/

class Solution {
public:
    int numTrees(int n) {
        vector<int> DP(n + 1, 0);
        DP[0] = 1;
        DP[1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++)
                DP[i] += DP[j - 1] * DP[i - j];
        }
        return DP[n];
    }
};