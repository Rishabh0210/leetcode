//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/

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
    void reverseLevelOrder(vector<TreeNode*> parents, vector<vector<int>>& solution) {
        if(parents.size() == 0)
            return;
        
        int i;
        vector<TreeNode*> children;
        vector<int> level;
        for(i = 0; i < parents.size(); i++) {
            TreeNode* root = parents[i];
            if(root -> left != NULL)
                children.push_back(root -> left);
            if(root -> right != NULL)
                children.push_back(root -> right);
            
            level.push_back(root -> val);
        }
        
        reverseLevelOrder(children, solution);
        solution.push_back(level);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> solution;
        if(root == NULL)
            return solution;
        
        vector<TreeNode*> parent;
        parent.push_back(root);
        
        reverseLevelOrder(parent, solution);
        
        return solution;
    }
};