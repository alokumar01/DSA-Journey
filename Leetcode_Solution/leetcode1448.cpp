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
    int good = 0;
    
    void dfs(TreeNode* root, int maxVal) {
        if(!root) return;
        
        if(root->val >= maxVal) {
            good++;
            maxVal = root->val;
        }

        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        dfs(root, root->val);
        return good;
    }
};

[ Time taken: 1 hr 54 m 4 s ]
I have solved this using DFS, with Time Complexity O(N), Space O(N), recursive stack.
We can solve this by BFS(queue) as well, 


//Below is solved using BFS
    int goodNodes(TreeNode* root) {
        //Using BFS, TC-->O(N), SC-->O(h)
        if(!root) return 0;

        int count = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()) {
            auto [node, maxVal] = q.front();
            q.pop();

            if (node->val >= maxVal) {
                count++;
                maxVal = node->val;
            }

            if(node->left) {
                q.push({ node->left, maxVal });
            }

            if(node->right) {
                q.push({ node->right, maxVal });
            }
        }

        return count;
    }