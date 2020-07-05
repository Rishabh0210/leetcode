//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/

class Solution {
private:
    void traverse(vector<vector<char>>& copy, vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        
        int row[] = {0, 0, -1, 1};
        int col[] = {-1, 1, 0, 0};
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < 4; i++) {
            int R = r + row[i];
            int C = c + col[i];
            
            if(R >= 0 && R < n && C >= 0 && C < m && copy[R][C] == 'O' && !visited[R][C]){
                board[R][C] = 'O';
                traverse(copy, board, visited, R, C);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<char>> copy = board;
        int i, j;
        for(i = 1; i < n - 1; i++) {
            for(j = 1; j < m - 1; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        // for(i = 0; i < n; i++) {
        //     for(j = 0; j < m; j++)
        //         cout << board[i][j] << " ";
        //     cout << endl;
        // }
        for(i = 0; i < m; i++) {
            if(board[0][i] == 'O' && !visited[0][i])
                traverse(copy, board, visited, 0, i);
        }
        for(i = 0; i < m; i++) {
            if(board[n - 1][i] == 'O' && !visited[n - 1][i])
                traverse(copy, board, visited, n - 1, i);
        }
        for(i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !visited[i][0])
                traverse(copy, board, visited, i, 0);
        }
        for(i = 0; i < n; i++) {
            if(board[i][m - 1] == 'O' && !visited[i][n - 1])
                traverse(copy, board, visited, i, n - 1);
        }
    }
};