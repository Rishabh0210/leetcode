//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSolution(root, &k);    
    }
    
    int kthSolution(TreeNode* root, int* k) {
        int ans = 0;
        if(root -> left != NULL) {
            ans = kthSolution(root -> left, k);
        }
        if(*k == 1) {
            *k -= 1;
            return root -> val;
        }
        *k -= 1;
        if(*k >= 1 && root -> right != NULL) {
            ans = kthSolution(root -> right, k);
        }
        return ans;
    }
};