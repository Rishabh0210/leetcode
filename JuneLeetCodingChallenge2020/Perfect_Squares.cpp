//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3373/

class Solution {
public:
    int numSquares(int n) {
        int i;
        vector<int> squares;
        
        i = 1;
        while(i*i <= n) {
            squares.push_back(i*i);
            i++;
        }
        vector<vector<int>> DP(n + 1, vector<int>(squares.size(), 0));
        
        int j;
        for(i = 1; i <= n; i++) {
            for(j = 0; j < squares.size(); j++) {
                if(j == 0)
                    DP[i][j] = i;
                else {
                    int remaining_sum = INT_MAX;
                    if(i - squares[j] >= 0)
                        remaining_sum = DP[i - squares[j]][j] + 1;
                    DP[i][j] = min(DP[i][j - 1], remaining_sum);
                }
            }
        }
        
        for(i = 0; i < squares.size(); i++)
            cout << squares[i] << " ";
        cout << endl;
        
        for(i = 0; i <= n; i++) {
            for(j = 0; j < squares.size(); j++)
                cout << DP[i][j] << " ";
            cout << endl;
        }
        return DP[n][squares.size() - 1];
    }
};