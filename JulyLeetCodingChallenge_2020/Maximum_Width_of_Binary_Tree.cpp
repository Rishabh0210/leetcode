//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            cout << "lol";
            return 0;
        }
            
        
        unsigned long long int start = 0, end = 0, max_width = 0, level_width = 0;
        queue<TreeNode*> mainQ;
        queue<unsigned long long int> nodePos;
        
        mainQ.push(root);
        nodePos.push(1);
        
        while(!mainQ.empty()) {
            start = 0;
            end = 0;
            level_width = 0;
            
            queue<TreeNode*> temp;
            queue<unsigned long long int> childPos;
            
            while(!mainQ.empty()) {
                TreeNode* node = mainQ.front();
                mainQ.pop();
                unsigned long long int pos = nodePos.front();
                nodePos.pop();
                
                if(start == 0) {
                    start = pos;
                } 
                end = pos;
                
                
                if(node -> left != NULL) {
                    temp.push(node -> left);
                    childPos.push(2 * pos - 1);
                }
                if(node -> right != NULL) {
                    temp.push(node -> right);
                    childPos.push(2 * pos);
                }
            }
            
            level_width = end - start + 1;
            max_width = max(max_width, level_width);
            
            while(!temp.empty()) {
                TreeNode* node = temp.front();
                temp.pop();
                unsigned long long int pos = childPos.front();
                childPos.pop();
                
                mainQ.push(node);
                nodePos.push(pos);
            }
        }
        return (int)max_width;
    }
};