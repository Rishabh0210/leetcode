//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3369/

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
    int countNodes(TreeNode* root) {
        int c = 0;
        if(root != NULL)
            count(root, c);
        return c;
    }
    
    void count(TreeNode* root, int& c) {
        if(root -> left != NULL)
            count(root -> left, c);
        
        c++;
        
        if(root -> right != NULL) 
            count(root -> right, c);
    }
};