/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size() > 0) {
            TreeNode* curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {xx`x`x`
                q.push(curr->right);
            }
        }
        
        return root; 
    }
};