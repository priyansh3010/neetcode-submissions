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
    bool validate(TreeNode* node, int minValue, int maxValue) {
        if (node == nullptr) return true;
        
        if (node->val <= minValue || node->val >= maxValue) return false;
        return validate(node->left, minValue, node->val) 
            && validate(node->right, node->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }
};
