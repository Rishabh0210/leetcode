//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3340/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int l = A.size(), m = B.size();
        vector<vector<int>> DP(l, vector<int>(m, 0));
        int i, j;
        
        if(A[0] == B[0])
            DP[0][0] = 1;
        for(i = 1; i < m; i++) {
            if(A[0] == B[i])
                DP[0][i] = 1;
            DP[0][i] = max(DP[0][i], DP[0][i - 1]);
        }
        
        for(i = 1; i < l; i++) {
            if(A[i] == B[0])
                DP[i][0] = 1;
            DP[i][0] = max(DP[i][0], DP[i - 1][0]);
        }
        
        for(i = 1; i < l; i++) {
            for(j = 1; j < m; j++) {
                if(A[i] == B[j])
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                DP[i][j] = max(DP[i][j], max(DP[i - 1][j], DP[i][j - 1]));
            }
        }
            
        return DP[l - 1][m - 1];
    }
    
    int maxCross(vector<int>& A, vector<int>& B, int start_a, int start_b) {
        if(start_a == A.size())
            return 0;
        int i;
        int max_ans = 0;
        int ans1 = 0, ans2 = 0;
        for(int j = start_a; j < A.size(); j++) {
            for(i = start_b; i < B.size(); i++) {
                if(A[j] == B[i]) {
                    ans1 = maxCross(A, B, j + 1, i + 1);
                    max_ans = max(max_ans, ans1 + 1);    
                }
            }   
        }
        return max_ans;
    }
};