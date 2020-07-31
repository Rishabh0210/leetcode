//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3401/

class Solution {
private:
    int findMinimum(vector<int>& arr, int low, int high) { 
        cout << "low: " << low << " high: " << high << endl;
        // This condition is needed to handle the case when array 
        // is not rotated at all 
        if (high < low)  return arr[0]; 
  
        // If there is only one element left 
        if (high == low) return arr[low]; 
  
        // Find mid 
        int mid = low + (high - low)/2; /*(low + high)/2;*/
        int leftUnique = mid - 1;
        int rightUnique = mid + 1;
        
        while(leftUnique >= low && arr[leftUnique] == arr[mid])
            leftUnique--;
        while(rightUnique <= high && arr[rightUnique] == arr[mid])
            rightUnique++;
  
        // Check if element (mid+1) is minimum element. Consider 
        // the cases like {3, 4, 5, 1, 2} 
        if (rightUnique <= high && mid < high && arr[rightUnique] < arr[mid]) 
            return arr[rightUnique]; 
  
        // Check if mid itself is minimum element 
        if (leftUnique >= low && mid > low && arr[mid] < arr[leftUnique]) 
            return arr[mid]; 
  
        // Decide whether we need to go to left half or right half 
        if (arr[high] >= arr[mid]) 
            return findMinimum(arr, low, mid - 1); 
        return findMinimum(arr, mid + 1, high); 
    }
public:
    int findMin(vector<int>& nums) {
        return findMinimum(nums, 0, nums.size() - 1);
    }
};