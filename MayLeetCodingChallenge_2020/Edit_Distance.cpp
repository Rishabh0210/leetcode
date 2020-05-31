//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l = word1.size();
        int m = word2.size();
        
        vector<vector<int>> DP(m + 1, vector<int> (l + 1, INT_MAX));
        int i, j;
        
        for(i = 0; i <= m; i++) {
            for(j = 0; j <= l; j++) {
                if(i == 0)
                    DP[i][j] = j;
                else if (j == 0)
                    DP[i][j] = i;
                else if (word1[j - 1] == word2[i - 1])
                    DP[i][j] = DP[i - 1][j - 1];
                else {
                    DP[i][j] = 1 + min(DP[i - 1][j], min(DP[i][j - 1], DP[i - 1][j - 1]));
                }
            }
        }
        for(i = 0; i <= m; i++) {
            for(j = 0; j <= l; j++)
                cout << DP[i][j] << " ";
            cout << endl;
        }
        return DP[m][l];
    }
};