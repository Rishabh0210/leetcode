//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        vector<int> row = {0, 0, -1, 1};
        vector<int> col = {1, -1, 0, 0};
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int neigh = 0;
                    for(int k = 0; k < 4; k++) {
                        int X = i + row[k];
                        int Y = j + col[k];
                        
                        if(X >= 0 && X < m && Y >= 0 && Y < n && grid[X][Y] == 1)
                            neigh++;
                    }
                    perimeter += 4 - neigh;
                }
            }
        }
        return perimeter;
    }
};