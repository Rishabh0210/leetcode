//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dict1[26], dict2[26], i;
        
        for(i = 0; i < 26; i++) {
            dict1[i] = 0;
            dict2[i] = 0;
        }
        
        for(i = 0; i < ransomNote.size(); i++)
            dict1[ransomNote[i] - 'a']++;
        for(i = 0; i < magazine.size(); i++)
            dict2[magazine[i] - 'a']++;
        
        for(i = 0; i < 26; i++) {
            if(dict1[i] > dict2[i])
                return false;
        }
        return true;
    }
};