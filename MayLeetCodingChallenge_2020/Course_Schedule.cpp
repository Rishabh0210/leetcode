//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/

class Solution {
private: 
    bool canFinishCourses (vector<int> adj[], vector<int> &color, int course) {
        if(color[course] == 1) { // the course is under process
            return false;       // a cycle exists
        } else if(color[course] == 2) { // the course has been processed
            return true;
        }
        color[course] = 1;
        for(int i = 0; i < adj[course].size(); i++) {
            if(!canFinishCourses(adj, color, adj[course][i]))
                return false;
        }
        
        color[course] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int i;
        vector<int> color; //there will be three colors- 0, 1, 2
        
        for (i = 0; i < numCourses; i++)
            color.push_back(0);         //not visited nodes
        
        for(i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            
            adj[a].push_back(b);
        }
        
        for(i = 0; i < numCourses; i++) {
            if(color[i] == 0) {
                if(!canFinishCourses(adj, color, i))
                    return false;
            }
        }
        return true;
    }
};