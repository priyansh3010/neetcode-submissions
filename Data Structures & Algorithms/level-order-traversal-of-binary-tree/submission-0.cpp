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
    int index = 0;
    vector<vector<int>> result;
public:
    // result = [[1], [2,3], [4,5,6,7]]
    // node = [,6,]
    // index = 2
    // currDepth = 2
    void traverse(TreeNode* node, int currDepth) {
        if (node == nullptr) return;
        
        if (currDepth > result.size()) {
            result.push_back({});
        }

        result[index].push_back(node->val);
        index++;
        traverse(node->left, currDepth + 1);
        traverse(node->right, currDepth + 1);
        index--;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        traverse(root, 1);
        return result;
    }
};
