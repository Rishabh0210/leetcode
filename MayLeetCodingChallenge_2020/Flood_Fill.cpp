//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visited;
        for(int i = 0; i < image.size(); i++) {
            vector<int> rows;
            for(int j = 0; j < image[0].size(); j++)
                rows.push_back(0);
            visited.push_back(rows);
        }
        
        floodFillAlgo(image, sr, sc, newColor, image[sr][sc], visited);
        
        return image;
    }
    
    void floodFillAlgo(vector<vector<int>>& image, int sr, int sc, int newColour, int oldColour, vector<vector<int>>& visited) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        
        if(image[sr][sc] == oldColour && visited[sr][sc] == 0) {
            image[sr][sc] = newColour;
            visited[sr][sc] = 1;
            
            floodFillAlgo(image, sr + 1, sc, newColour, oldColour, visited);
            floodFillAlgo(image, sr, sc + 1, newColour, oldColour, visited);
            floodFillAlgo(image, sr, sc - 1, newColour, oldColour, visited);
            floodFillAlgo(image, sr - 1, sc, newColour, oldColour, visited);
        }
    }
};