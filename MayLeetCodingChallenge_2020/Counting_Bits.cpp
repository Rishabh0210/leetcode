//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3343/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans; 
        ans.push_back(0);
        if(num >= 1)
            ans.push_back(1);
        
        
        int i = 1;
        
        while(ans.size() < num + 1) {
            
            ans.push_back(1);
            
            for(int j = pow(2, i) + 1; j <= num && j < pow(2, i + 1); j++) {
                if(j % 2 == 1) {
                    int prev =   ans[ans.size() - 1];
                     
                    ans.push_back(prev + 1);
                } else {
                    int remaining = j - pow(2, i);
                    int remaining_ones = ans[remaining];
                    
                    ans.push_back(1 + remaining_ones);
                }
            }
            i++;
        }
        return ans;
    }
};