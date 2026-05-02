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
    int count = 0;
    int result = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return 0;

        kthSmallest(root->left, k);
        count++;
        if (count == k) {
            result = root->val;
            return result;
        }
        kthSmallest(root->right, k);

        return result;
    }
};
