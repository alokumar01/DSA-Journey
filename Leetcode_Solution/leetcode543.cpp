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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        int m =  max(l, r) + 1;
        return m;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int currDim = height(root->left) + height(root->right);

        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
    
        return max(currDim, max(ld, rd));
    }
};