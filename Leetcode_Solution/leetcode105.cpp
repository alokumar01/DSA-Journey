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
    int search(vector<int>& inorder, int left, int right, int rootVal) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        // unboundary case
        if (left > right) return NULL;
        int rootVal = preorder[preIdx];
        preIdx++;

        TreeNode* root = new TreeNode(rootVal);

        int inIdx = search(inorder, left, right, rootVal);

        root->left = makeTree(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = makeTree(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return makeTree(preorder, inorder, preIdx, 0, preorder.size()-1);
    }
};