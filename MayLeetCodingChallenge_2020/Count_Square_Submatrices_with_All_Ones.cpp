//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int i, j;
        
        for(i = 0; i < matrix.size(); i++) 
            if(matrix[i][0] == 1)
                ans++;
        for(i = 1; i < matrix[0].size(); i++)
            if(matrix[0][i] == 1)
                ans++;
        
        for(i = 1; i < matrix.size(); i++)
            for(j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
                    ans += matrix[i][j];
                }
            }
        
        return ans;
    }
};