//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3391/

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i, l = s.size();
        string temp = "";
        for(i = 0; i < l; i++) {
            while(i < l && s[i] == ' ')
                i++;
            
            temp = "";
            while(i < l && s[i] != ' ')
                temp += s[i++];
            if(temp != "" && ans != "")
                ans = temp + ' ' + ans;
            else if(ans == "")
                ans = temp;
        }
        return ans;
    }
};