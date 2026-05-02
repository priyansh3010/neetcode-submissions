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
    int bestPath = INT_MIN;
public:
    int findPath(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = max(0, findPath(node->left));
        int right = max(0, findPath(node->right));
        bestPath = max(bestPath, left + right + node->val);
        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        findPath(root);
        return bestPath;
    }
};
