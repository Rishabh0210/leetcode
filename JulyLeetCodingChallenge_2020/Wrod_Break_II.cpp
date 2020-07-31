//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3406/

class Solution {
private: 
    bool startsWith(string str, string substring) {
        if(substring.size() > str.size())
            return false;
        for(int i = 0; i < substring.size(); i++) {
            if(substring[i] != str[i])
                return false;
        }
        return true;
    }
    vector<string> helper(string s, vector<string>& wordDict, map<string, vector<string>>& memo){
        if(memo.find(s) != memo.end()){
            return memo[s];
        }
        vector<string> res;
        if(s.size() == 0){
            res.push_back("");
            return res;
        }
        for(string word : wordDict){
            if(startsWith(s, word)){
                string sub = s.substr(word.size(), s.size() - word.size());
                vector<string> subStrings = helper(sub, wordDict, memo);
                for(string substring:subStrings){
                    //if our string is empty we don't want space in it
                    string optionalSpace = substring.size() == 0 ? "" : " ";  
                    res.push_back(word+optionalSpace+substring);
                }
            }
        }
        memo[s] = res;
        return res;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> solution;
        string temp = "cats";
        map<string, vector<string>> memo;
        return helper(s, wordDict, memo);
    }
};