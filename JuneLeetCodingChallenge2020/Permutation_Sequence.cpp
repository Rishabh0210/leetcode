//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string ans = "";
        vector<bool> nums(n, true);
        vector<int> factorial;
        
        int i;
        factorial.push_back(1);
        for(i = 1; i < n; i++) {
            factorial.push_back(factorial[factorial.size() - 1] * i);
        }
        
        int s = nums.size();
        
        while(k > 1) {
            int c = k/factorial[n - 1];
            if(k % factorial[n - 1] != 0)
                c++;
            
            i = 0;
            while(c && i < s) {
                if(nums[i]) {
                    c--;
                }
                i++;
            }

            ans += (i + '0');
            nums[i - 1] = false;
            
            k %= factorial[n - 1];
            n--;
        }
        
        if(k == 1) {
            for(i = 0; i < s; i++) {
                if(nums[i])
                    ans += (i + 1 + '0');
            }
        } else {
            for(i = s - 1; i >= 0; i--) {
                if(nums[i])
                    ans += (i + 1 + '0');
            }
        }
        // char h = (10 - '0');
        // cout << h;
        return ans;
    }
};