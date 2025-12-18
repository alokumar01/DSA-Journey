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
    int dfsHelper(TreeNode* root, int& maxSum) {
        if (root == NULL) return 0;

        int leftVal = max(0, dfsHelper(root->left, maxSum));
        int rightVal = max(0, dfsHelper(root->right, maxSum));

        int currSum = leftVal + rightVal + root->val;
        maxSum = max(maxSum, currSum);

        return max(leftVal , rightVal) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfsHelper(root, maxSum);
        return maxSum;
    }
};



// Binary Tree Maximum Path Sum — Quick Revision

// 1. Core Idea
// Use post-order DFS
// Solve with Tree DP

// 2. Two Values at Every Node
// Local path (can split):
// left + node + right
// Used to update global max
// Return path (cannot split):
// node + max(left, right)
// Sent to parent

// 3. Handling Negatives
// Ignore negative subtree contributions
// Use: max(0, subtreeSum)

// 4. Global Variable (maxSum)
// Stores best path anywhere
// Updated at every node
// Needed because best path may not reach root

// 5. Return Value Rule
// Must be a single downward path
// Cannot include both children

// Return:
// node.val + max(leftGain, rightGain)

// 6. Turning Point Concept
// Each node is treated as a possible highest point
// Only place where both children are allowed together

// 7. Edge Case
// All values negative → answer is max single node
// Still works because global max is updated independently

// 8. Complexity
// Time: O(n)
// Space: O(h) (recursion stack)

// 9. Interview One-Liner
// “At each node, update the global answer using both sides,
// and return only one side upward.”