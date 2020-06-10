//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/

class Solution {
private:
    static bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
        return p1.second > p2.second;
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<pair<int, int>, int>> weight;
        
        int i, n = costs.size();
        
        for(i = 0; i < n; i++) {
            pair<int, int> p1 = make_pair(costs[i][0], costs[i][1]);
            
            int diff = abs(costs[i][0] - costs[i][1]);
            
            pair<pair<int, int>, int> p2 = make_pair(p1, diff);
            weight.push_back(p2);
        }
        
        sort(weight.begin(), weight.end(), compare);
        
        int A = n/2, B = n/2;
        int ans = 0;
        for(i = 0; i < n; i++) {
            pair<int, int> p = weight[i].first;
            
            if(A > 0 && B > 0) {
                if(p.first < p.second) {
                    A--;
                    ans += p.first;
                } else {
                    B--;
                    ans += p.second;
                }
            } else if (A > 0) {
                A--;
                ans += p.first;
            } else {
                B--;
                ans += p.second;
            }
        }
        return ans;
    }
};