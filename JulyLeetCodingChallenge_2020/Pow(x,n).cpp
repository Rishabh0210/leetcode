//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3392/

class Solution {
private:
    double power(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        double result = power(x, n/2);
        if(n%2==0)
            return result*result;
        
        return result*result*x;
    }
public:
    double myPow(double x, int n) {
        bool flag = false;
        if(n < 0)
            flag = true;
        
        double result = power(x, abs(n));
        if(flag)
            return (1.0/result);
        return result;
    }
};