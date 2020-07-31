//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3400/

class Solution {
private:
    void DFS(int n, vector<int> path, vector<vector<int>>& paths, vector<vector<int>>& graphs) {
        if(n == graphs.size() - 1) {
            path.push_back(n);
            paths.push_back(path);
            return;
        }
        path.push_back(n);
        for(int i = 0; i < graphs[n].size(); i++) {
            DFS(graphs[n][i], path, paths, graphs);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        
        vector<int> path;
        path.push_back(0);
        for(int i = 0; i < graph[0].size(); i++) {
            DFS(graph[0][i], path, paths, graph);
        }
        
        return paths;
    }
};