//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        if(root == NULL)
            return solution;
        
        int level = 1;
        stack<TreeNode*> curr;
        curr.push(root);
        
        while(!curr.empty()) {
            stack<TreeNode*> temp;
            vector<int> levelValues;
            while(!curr.empty()) {
                TreeNode* topNode = curr.top();
                curr.pop();
                
                levelValues.push_back(topNode -> val);
                
                if(level%2 == 0) {
                    if(topNode -> right)
                        temp.push(topNode -> right);
                    if(topNode -> left)
                        temp.push(topNode -> left);
                } else {
                    if(topNode -> left)
                        temp.push(topNode -> left);
                    if(topNode -> right)
                        temp.push(topNode -> right);
                }
            }
            
            solution.push_back(levelValues);
            level++;
            curr = temp;
        }
        return solution;
    }
};