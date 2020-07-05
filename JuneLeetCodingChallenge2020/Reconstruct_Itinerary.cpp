//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3374/

class Solution {
private:
    map<string, priority_queue <string, vector<string>, greater<string>>> flights;
    stack<string> solution;
    
    void DFS(string dep) {
        // cout << dep << endl;
        
        
        while(!flights[dep].empty()) {
            string arrival = flights[dep].top();
            flights[dep].pop();
            DFS(arrival);
        }
        solution.push(dep);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        
        int i;
        for(i = 0; i < tickets.size(); i++) {
            if(flights.find(tickets[i][0]) == flights.end()) {
                priority_queue <string, vector<string>, greater<string>> pq;
                flights[tickets[i][0]] = pq;
            }
            flights[tickets[i][0]].push(tickets[i][1]);   
        }
        DFS("JFK");
        while(!solution.empty()) {
            ans.push_back(solution.top());
            solution.pop();
        }
        return ans;
    }
};