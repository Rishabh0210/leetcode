//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2)
            return true;
        
        int x1, x2, y1, y2;
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        
        x2 = coordinates[1][0];
        y2 = coordinates[1][1];
        
        for(int i = 2; i < coordinates.size(); i++) {
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            
            //calculate the area of the triangle formed by (x1, y1), (x2, y2), (x3, y3)
            int ar = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
            if(ar != 0)
                return false;
        }
        return true;
    }
};