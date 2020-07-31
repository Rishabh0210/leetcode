//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string ans = "";
        char c = '0';
        
        while(i >= 0 && j >= 0) {
            char A = a[i];
            char B = b[j];
            
            if(A == '1' && B == '1' && c == '1') {
                ans = '1' + ans;
                c = '1';
            } else if ((A == '1' && B == '1' && c == '0')
                      || (A == '1' && B == '0' && c == '1')
                      || (A == '0' && B == '1' && c == '1')) {
                ans = '0' + ans;
                c = '1';
            } else if((A == '1' && B == '0' && c == '0')
                     || (A == '0' && B == '1' && c == '0')
                     || (A == '0' && B == '0' && c == '1')) {
                ans = '1' + ans;
                c = '0';
            } else {
                ans = '0' + ans;
            }
            i--;
            j--;
        }
        
        while(i >= 0) {
            if(a[i] == '1' && c == '1') {
                ans = '0' + ans;
                c = '1';
            } else if((a[i] == '1' && c == '0') || (a[i] == '0' && c == '1')) {
                ans = '1' + ans;
                c = '0';
            } else {
                ans = '0' + ans;
            }
            i--;
        }
        
        while(j >= 0) {
            if(b[j] == '1' && c == '1') {
                ans = '0' + ans;
                c = '1';
            } else if((b[j] == '1' && c == '0') || (b[j] == '0' && c == '1')) {
                ans = '1' + ans;
                c = '0';
            } else {
                ans = '0' + ans;
            }
            j--;
        }
        if(c == '1')
            ans = '1' + ans;
        
        return ans;
    }
};