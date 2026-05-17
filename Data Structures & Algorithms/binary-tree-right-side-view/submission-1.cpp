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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeNode* mostRecent;

            for (int i = 0; i < size; i++) {
                mostRecent = q.front(); q.pop();
                if (mostRecent->left) q.push(mostRecent->left);
                if (mostRecent->right) q.push(mostRecent->right);
            }

            result.push_back(mostRecent->val);
        }

        return result;
    }
};
