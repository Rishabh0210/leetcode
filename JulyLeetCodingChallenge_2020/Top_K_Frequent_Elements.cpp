//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/

class Solution {
private:
    struct compare { 
        bool operator()(pair<int, int> p1, pair<int, int> p2) 
        { 
            // if frequencies of two elements are same 
            // then the larger number should come first 
            if (p1.second == p2.second) 
                return p1.first < p2.first; 

            // insert elements in the priority queue on the basis of 
            // decreasing order of frequencies 
            return p1.second < p2.second; 
        } 
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um; 
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            um[nums[i]]++; 

        vector<pair<int, int> > freq_arr(um.begin(), um.end()); 

        priority_queue<pair<int, int>, vector<pair<int, int> >, 
                       compare> 
            pq(um.begin(), um.end()); 

        vector<int> ans;
        for (int i = 1; i <= k; i++) { 
            ans.push_back(pq.top().first);
            pq.pop(); 
        } 
        return ans;
    }
};