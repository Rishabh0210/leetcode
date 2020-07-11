//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> solution(digits.size());
        int c = 1;
        
        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + c;
            c = sum / 10;
            solution[i] = sum % 10;
        }
        if(c != 0) {
            solution.push_back(0);
            for(int i = digits.size(); i > 0; i--)
                solution[i] = solution[i - 1];
            
            solution[0] = c;
        }
        
        return solution;
    }
};