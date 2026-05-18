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
    int result;
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        result = 0;
        traverse(root, root->val);

        return result;
    }

    void traverse(TreeNode* node, int currMax) {
        if (!node) return;
        
        if (node->val >= currMax) result++;
        traverse(node->left, max(currMax, node->val));
        traverse(node->right, max(currMax, node->val));
    }
};