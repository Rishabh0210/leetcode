//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* x_parent = NULL;
        TreeNode* y_parent = NULL;
        int x_height = -1;
        int y_height = -1;
        x_parent = findParent(root, x, &x_height);
        y_parent = findParent(root, y, &y_height);
        
        if(x_height == y_height){
            if(x_parent != y_parent)
                return true;
            else
                return false;
        } 
        return false;
    }
    
    TreeNode* findParent(TreeNode* root, int x, int *height) {
        if(root == NULL)
            return NULL;
        if(root -> val == x){
            *height = 0;
            return NULL;
        } 
        TreeNode* leftParent = findParent(root -> left, x, height);
        
        if(leftParent != NULL || *height != -1) {
            if(*height == 0) {
                *height += 1;
                return root;
            }
            *height += 1;
            return leftParent;
        } else {
            TreeNode* rightParent = findParent(root -> right, x, height);
            if(rightParent != NULL || *height != -1) {
                if(*height == 0) {
                    *height += 1;
                    return root;
                }
                *height += 1;
                return rightParent;
            }
        }
        return NULL;   
    }
};