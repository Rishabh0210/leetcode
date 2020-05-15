//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(N == 1) {
            if(trust.size() == 0)
                return 1;
            return -1;
        }
        unordered_map<int, int> trustees, trusting;
        
        int i, j;
        
        for(i = 0; i < trust.size(); i++){
            if(trusting.find(trust[i][0]) != trusting.end())
                trusting[trust[i][0]]++;
            else
                 trusting[trust[i][0]] = 1;
            
            if(trustees.find(trust[i][1]) != trustees.end())
                trustees[trust[i][1]]++;
            else
                 trustees[trust[i][1]] = 1;
        }
        int ans = -1;
        for(auto i : trustees) {
            if(i.second == N - 1)
                if(trusting.find(i.first) == trusting.end()) {
                    ans = i.first;
                    break;
                }
        }
        return ans;
    }
};