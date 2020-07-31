//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3394/

class Solution {
private:
    bool DFS(vector<vector<int>>& adjacency, vector<int>& coursesDone, vector<int>& ans, int course) {
        if(coursesDone[course] == 1)
            return false;
        if(coursesDone[course] == 2)
            return true;
        
        
        coursesDone[course] = 1;
        for(int i = 0; i < adjacency[course].size(); i++) {
            if(!DFS(adjacency, coursesDone, ans, adjacency[course][i]))
                return false;
        }
        ans.push_back(course);
        coursesDone[course] = 2;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adjacency(numCourses);
        vector<int> coursesDone(numCourses, 0);
        int i;
        
        for(i = 0; i < prerequisites.size(); i++) {
            adjacency[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(i = 0; i < numCourses; i++) {
            if(coursesDone[i] == 0) {
                if(!DFS(adjacency, coursesDone, ans, i)) {
                    vector<int> solution;
                    return solution;
                }
            }
        }
        return ans;
    }
};