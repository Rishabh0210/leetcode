//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/

class Solution {
private:
    string IPv4Set = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
    string IPv6Set = "([0-9a-fA-F]{1,4})"; 
    string IP4rex  = "^(" + IPv4Set + "\\.){3}" + IPv4Set + "$";
    string IP6rex  = "^(" + IPv6Set + "\\:){7}" + IPv6Set + "$"; 
public:
    string validIPAddress(string IP) {
        regex IP4(IP4rex);
        regex IP6(IP6rex);
        
        if(regex_match(IP, IP4))
            return "IPv4";
        else if(regex_match(IP, IP6))
            return "IPv6";
        return "Neither";
    }
};