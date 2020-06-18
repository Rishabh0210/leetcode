//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l, h;
        l = 0;
        h = citations.size() - 1;
        int N = citations.size();
        if(N == 0)
            return 0;
        
        while(l <= h) {
            int m = l + (h - l)/2;
            
            if(m == N - citations[m]) return citations[m];
            else if(m > N - citations[m]) h = m - 1;
            else l = m + 1;
            
        }
        
        
        return N - l;
    }
};