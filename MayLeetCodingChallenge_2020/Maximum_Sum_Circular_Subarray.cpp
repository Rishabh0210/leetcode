//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int pos_max = kadaneSum(A, 1);			//gives the maximum positive sum
        int neg_max = kadaneSum(A, -1);			//gives the maximum negative sum
        
        int total = 0;
        bool all_neg = true;
        for(int i = 0; i < A.size(); i++) {
            total += A[i];
            if(A[i] >= 0)
                all_neg = false;
        }
        
        if(all_neg)
            return pos_max;
        return max(pos_max, total + neg_max);	//(total + neg_max) excludes the maximum negative sum subarray from
        										//the whole array to give the maximum circular sum 
    }
    
    int kadaneSum(vector<int>& A, int negVal) {
        int local_max = negVal * A[0];
        int maximum = negVal * A[0];
        
        for(int i = 1; i < A.size(); i++) {
            local_max = max(local_max + (negVal * A[i]), (negVal * A[i]));
            
            maximum = max(maximum, local_max);
        }
        return maximum;
    }
};