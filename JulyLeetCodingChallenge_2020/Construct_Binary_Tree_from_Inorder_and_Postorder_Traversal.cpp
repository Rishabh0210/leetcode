//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3403/

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
    TreeNode* treeHelper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, 
                         int& postIndex) {
        if(inS > inE)
            return NULL;
        
        TreeNode* root = createNode(postorder[postIndex]);
        postIndex--;
        
        if(inS == inE)
            return root;
        
        int inIndex = findRootIndex(inorder, inS, inE, root -> val);
        
        root -> right = treeHelper(inorder, postorder, inIndex + 1, inE, postIndex);
        root -> left = treeHelper(inorder, postorder, inS, inIndex - 1, postIndex);
        
        return root;
    }
    int findRootIndex(vector<int> inorder, int inS, int inE, int val){
        for(int i = inS; i <= inE; i++){
            if(inorder[i] == val)
                return i;
        }    
        return 0;
    }
    
    TreeNode* createNode(int val) {
        TreeNode* node = new TreeNode();
        node -> val = val;
        node -> left = NULL;
        node -> right = NULL;
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return treeHelper(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};