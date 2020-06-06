//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/

class Solution {
private: 
    static bool compare(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        int n = people.size();
        vector<vector<int>> ans(n, vector<int>(2, INT_MAX));
        
        int i;
        for(i = 0; i < n; i++) {
            int person_in_front = people[i][1];
            int j = 0;
            for(j = 0; j < n; j++) {
                if(ans[j][0] == INT_MAX && person_in_front == 0)
                    break;
                else if(ans[j][0] == INT_MAX || ans[j][0] == people[i][0])
                    person_in_front--;
            }
            ans[j][0] = people[i][0];
            ans[j][1] = people[i][1];
        }
        
        return ans;
    }
};