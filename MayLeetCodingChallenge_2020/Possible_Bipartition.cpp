//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj;
        vector<int> color;
        int i;
        queue<int> nodes;
        
        
        for(i = 0; i <= N; i++) {
            vector<int> neigh;
            adj.push_back(neigh);
            color.push_back(0);
        }
        for(i = 0; i < dislikes.size(); i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        // for(i = 0; i <= N; i++) {
        //     cout << i<< "- ";
        //     for(int j = 0; j < adj[i].size(); j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for(i = 1; i <= N; i++) {
            if(color[i] == 0) {
                color[i] = -1;
                nodes.push(i);
                
                while(!nodes.empty()) {
                    int node = nodes.front();
                    nodes.pop();
                    cout << node << "- color-->" << color[node] << " neigh-->";
                    for(int j = 0; j < adj[node].size(); j++) {
                        int neighbour = adj[node][j];
                        
                        cout << neighbour << " neigh color->" << color[neighbour] << " ";
                        if(color[neighbour] == 0) {
                            color[neighbour] = color[node]*-1;
                            nodes.push(neighbour);
                        } else if(color[neighbour] == color[node]){
                            return false;
                        }
                    }
                    cout << endl;
                    
                }
            }
        }
        return true;
    }
};