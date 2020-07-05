//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3360/

class Solution {
private:
    void DFS(vector<vector<pair<int,int>>>& adj, int src, int dst, int K, vector<int>& visited, int cost, int& ans) {
        if(src == dst) {
            ans = cost;
            return;
        }
        if(K < 0)
            return;
        
        for(int i = 0; i < adj[src].size(); i++) {
            pair<int, int> p = adj[src][i];
            if(visited[p.first] == 1)
                continue;
            if(cost + p.second > ans)
                continue;
            
            visited[p.first] = 1;
            DFS(adj, p.first, dst, K - 1, visited, cost + p.second, ans);
            visited[p.first] = 0; 
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        int i, j;
        for(i = 0; i < flights.size(); i++) {
            int a = flights[i][0];
            int b = flights[i][1];
            int c = flights[i][2];
            adj[a].push_back(make_pair(b,c));
        }
        vector<int> visited(n, 0);
        visited[src] = 1;
        int ans = INT_MAX;
        
        DFS(adj, src, dst, K, visited, 0, ans);
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};