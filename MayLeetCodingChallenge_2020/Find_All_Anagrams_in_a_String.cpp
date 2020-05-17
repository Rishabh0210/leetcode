//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> dictP, ans;
        vector<int> dictS;
        int i, j, l, m;
        
        initialiseDict(dictP);
        initialiseDict(dictS);
        l = s.size();
        m = p.size();
        
        if(l < m)
            return ans;
        
        for(i = 0; i < m; i++) {
            dictP[p[i]]++;
            dictS[s[i]]++;
        }
        dictS[s[m - 1]]--;
        
        for(i = m - 1; i < l; i++) {
            dictS[s[i]]++;
            int flag = 1;
            for(j = 0; j < 256; j++)
                if(dictS[j] != dictP[j]) {
                    flag = 0;
                    break;
                }
            if(flag)
                ans.push_back(i + 1 - m);
            dictS[s[i + 1 - m]]--;
        }
        return ans;
    }
    
    void initialiseDict(vector<int>& freq) {
        int i;
        for(i = 0; i < 256; i++)
            freq.push_back(0);
    }
};