//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/

class Solution {
public:
    vector<int> cumWeight;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i = 0; i < w.size(); i++) {
            sum += w[i];
            cumWeight.push_back(sum);
        }
    }
    
    int pickIndex() {
        int upper_limit = cumWeight[cumWeight.size() - 1];
        int target = rand() % upper_limit;
        int mid, ans, high, low;
        high = cumWeight.size() - 1;
        low = 0;
        ans = -1;
        
        while(low <= high) {
            mid = (low + (high - low)/2);
            if(target < cumWeight[mid]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */