//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/

class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k) {
            int i = 0;
            while(i < num.size() - 1 && num[i] <= num[i + 1])
                i++;
            
            num.erase(i, 1);
            k--;
        }
        
        while(num.size() > 1 && num[0] == '0'){
            num.erase(0, 1);
        }
        
        if(num.size() == 0)
            return "0";
        
        return num;
    }
};