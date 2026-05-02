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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        TreeNode* traverseNode = root;

        while (true) {
            if (traverseNode == nullptr) break;
            
            if (traverseNode->val > q->val) {
                traverseNode = traverseNode->left;
                continue;
            } 
            else if (traverseNode->val < p->val) {
                traverseNode = traverseNode->right;
                continue;
            }

            if (traverseNode->val == p->val || traverseNode->val == q->val) return traverseNode;

            if ((traverseNode->left != nullptr && traverseNode->left->val <= p->val)
            &&  (traverseNode->right != nullptr) && traverseNode->right->val >= q->val) return traverseNode;
        }

        return root;
    }
};
