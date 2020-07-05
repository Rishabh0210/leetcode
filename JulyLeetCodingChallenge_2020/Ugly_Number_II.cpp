//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/

class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> ugly_num;
        ugly_num.push_back(1);
        
        while(ugly_num.size() < n) {
            int two_multiple = 2 * ugly_num[i];
            int three_multiple = 3 * ugly_num[j];
            int five_multiple = 5 * ugly_num[k];
            
            int next_ugly = min(two_multiple, min(three_multiple, five_multiple));
            if(next_ugly == two_multiple) i++;
            if(next_ugly == three_multiple) j++;
            if(next_ugly == five_multiple) k++;
            
            ugly_num.push_back(next_ugly);
        }
        return ugly_num[n - 1];
    }
};