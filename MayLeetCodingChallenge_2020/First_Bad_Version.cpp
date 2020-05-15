//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l, h, mid;
        
        l = 1;
        h = n;
        
        while(l < h) {
            mid = (l + h) / 2;
            bool isMidBad = isBadVersion(mid);
            
            if(isMidBad) {
                h = mid;
            } 
            else
                l = mid + 1;
        }
        return (int)l;
    }
};