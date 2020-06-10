//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        int i = 0, j = 0;
        while(i < l2 && j < l1) {
            if(t[i] == s[j])
                j++;
            i++;
        }
        return j == l1;
    }
};