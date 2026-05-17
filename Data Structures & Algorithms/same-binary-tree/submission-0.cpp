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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        result = true;

        traverse(p, q);
        return result;
    }

    void traverse(TreeNode* p, TreeNode* q) {
        if (!result) return;

        if (p == nullptr || q == nullptr) {
            if (p != q) result = false;
            return;
        }

        if (p->val != q->val) result = false;
        traverse(p->left, q->left);
        traverse(p->right, q->right);
    }
};
