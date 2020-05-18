//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/


class Solution {
public:
    bool checkInclusion(string s1, string s2) { 
        vector<int> dictS1;
        vector<int> dictS2;
        int i, j, l, m;
        
        initialiseDict(dictS1);
        initialiseDict(dictS2);
        l = s2.size();
        m = s1.size();
        
        if(l < m)
            return false;
        
        for(i = 0; i < m; i++) {
            dictS1[s1[i]]++;
            dictS2[s2[i]]++;
        }
        dictS2[s2[m - 1]]--;
        
        for(i = m - 1; i < l; i++) {
            dictS2[s2[i]]++;
            int flag = 1;
            for(j = 0; j < 256; j++)
                if(dictS2[j] != dictS1[j]) {
                    flag = 0;
                    break;
                }
            if(flag)
                return true;
            dictS2[s2[i + 1 - m]]--;
        }
        return false;
    }
    
    void initialiseDict(vector<int>& freq) {
        int i;
        for(i = 0; i < 256; i++)
            freq.push_back(0);
    }
};