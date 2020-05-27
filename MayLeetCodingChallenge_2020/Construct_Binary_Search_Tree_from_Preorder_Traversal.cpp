//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        
        TreeNode* ans = utilMethod(preorder, &index, INT_MIN, INT_MAX);
        
        return ans;
    }
    
    TreeNode* utilMethod (vector<int>& preorder, int* index, int min, int max) {
        
        if(preorder.size() == 0) 
            return NULL;
        
        if(*index >= preorder.size())
            return NULL;
        
        TreeNode* root = NULL;
        
        if(preorder[*index] >= min && preorder[*index] <= max) {
            root = getNewNode(preorder[*index]);
            
            int key = preorder[*index];
            
            *index = *index + 1;
            
            root -> left = utilMethod(preorder, index, min, key);
            root -> right = utilMethod(preorder, index, key, max);
        }
        
        return root;
    }
    
    TreeNode* getNewNode (int val) {
        TreeNode* newNode = new TreeNode();
        
        newNode -> val = val;
        
        newNode -> left = newNode -> right = NULL;
        
        return newNode;
    }
};