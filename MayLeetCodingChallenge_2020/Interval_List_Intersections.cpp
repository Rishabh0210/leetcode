//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int l = A.size();
        int m = B.size();
        int i = 0, j = 0;
        
        vector<vector<int>> ans;
        
        while(i < l && j < m) {
            int start_a = A[i][0], end_a = A[i][1];
            int start_b = B[j][0], end_b = B[j][1];
            vector<int> temp;
            if(end_a < start_b)
                i++;
            else if(end_b < start_a)
                j++;
            else if(start_a >= start_b && start_a <= end_b) {
               temp.push_back(start_a);
                if(end_a >= start_b && end_a <= end_b){
                    temp.push_back(end_a);
                    i++;
                } else {
                    temp.push_back(end_b);
                    j++;
                }
                ans.push_back(temp);
            } 
            else if(start_b >= start_a && start_b <= end_a) {
               temp.push_back(start_b);
                if(end_b >= start_a && end_b <= end_a){
                    temp.push_back(end_b);
                    j++;
                } else {
                    temp.push_back(end_a);
                    i++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};