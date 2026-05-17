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
    bool result;
public:
    bool isBalanced(TreeNode* root) {
        result = true;

        depthCount(root, 0);
        return result;
    }

    int depthCount(TreeNode* node, int currDepth) {
        if (node == nullptr) {
            return currDepth;
        }

        int leftDepth = depthCount(node->left, currDepth + 1);
        int rightDepth = depthCount(node->right, currDepth + 1);

        if (abs(rightDepth - leftDepth) > 1) result = false;
        return max(leftDepth, rightDepth);
    }
};
