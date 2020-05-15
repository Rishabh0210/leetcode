//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int i, j, ans = 0;
        
        for(i = 0; i < S.size(); i++){
            for(j = 0; j < J.size(); j++)
                if(S[i] == J[j]) {
                    ans++;
                    break;
                }
        }
        return ans;
    }
};