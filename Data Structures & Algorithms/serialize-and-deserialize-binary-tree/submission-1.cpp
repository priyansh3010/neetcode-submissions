class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#/";
        return to_string(root->val) + "/" + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string item;
        while (getline(ss, item, '/')) q.push(item);
        return dfs(q);
    }

private:
    TreeNode* dfs(queue<string>& q) {
        string val = q.front(); q.pop();
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = dfs(q);
        root->right = dfs(q);
        return root;
    }
};