//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N % 14 == 0) 
            N = 14;
        else
            N = N % 14;
        
        vector<int> temp = cells;
        int i, j;
        
        for(i = 1; i <= N; i++) {
            for(j = 1; j < cells.size() - 1; j++) {
                if(cells[j - 1] == cells[j + 1])
                    temp[j] = 1;
                else
                    temp[j] = 0;
            }
            temp[0] = 0;
            temp[cells.size() - 1] = 0;
            
            cells = temp;
        }
        return cells;
    }
};