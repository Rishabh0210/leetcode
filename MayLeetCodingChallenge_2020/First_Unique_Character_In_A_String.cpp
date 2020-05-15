//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

class Solution {
public:
    int firstUniqChar(string s) {
        int dict[26];
        int i;
        for(i = 0; i < 26; i++)
            dict[i] = 0;
        
        for(i = 0; i < s.size(); i++)
            dict[s[i] - 'a']++;
        
        for(i = 0; i < s.size(); i++)
            if(dict[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};