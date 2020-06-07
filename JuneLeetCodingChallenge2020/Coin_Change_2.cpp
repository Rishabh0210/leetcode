//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> DP(amount + 1, vector<int>(coins.size() + 1, 0));
        sort(coins.begin(), coins.end());
        
        
        int i, j;
        for(i = 0; i <= coins.size(); i++)
            DP[0][i] = 1;
        
        for(i = 1; i <= amount; i++) {
            for(j = 1; j <= coins.size(); j++) {
                if(i >= coins[j - 1])
                    DP[i][j] = DP[i - coins[j - 1]][j];
                DP[i][j] += DP[i][j - 1];
            }
        }
        return DP[amount][coins.size()];
    }
};