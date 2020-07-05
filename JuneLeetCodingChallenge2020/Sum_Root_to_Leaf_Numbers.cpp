//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/

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
private: 
    void inorderTraversal(TreeNode* root, int num_so_far, int& sum) {
        num_so_far = num_so_far * 10 + root -> val;
        
        if(root -> left == NULL && root -> right == NULL) {
            sum += num_so_far;
            return;
        }
        
        if(root -> left != NULL) {
            inorderTraversal(root -> left, num_so_far, sum);
        }
        
        if(root -> right != NULL) {
            inorderTraversal(root -> right, num_so_far, sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int num_so_far = 0;
        int sum = 0;
        
        if(root != NULL) {
            inorderTraversal(root, num_so_far, sum);
        }
        
        return sum;
    }
};