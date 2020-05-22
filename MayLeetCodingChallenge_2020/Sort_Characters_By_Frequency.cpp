//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/

class Solution {
public:
    static bool sortbysecdesc (const pair<int,int> &a, const pair<int,int> &b) { 
        return (a.second > b.second); 
    }
    
    string frequencySort(string s) {
        map<int, int> charFreqMap;
        int i;
        for(i = 0; i < s.size(); i++) {
            if(charFreqMap.find(s[i]) == charFreqMap.end())
                charFreqMap[s[i]] = 0;
            charFreqMap[s[i]]++;
        }
        vector<pair<int, int>> transformVector;
        
        copy(charFreqMap.begin(), charFreqMap.end(), back_inserter(transformVector));
        
        sort(transformVector.begin(), transformVector.end(), sortbysecdesc); 
        
        string ans = "";
        for(i = 0; i < transformVector.size(); i++) {
            pair<int, int> p = transformVector[i];
            for(int j = 0; j < p.second; j++) 
                ans += p.first;
        }
        return ans;
    }
};