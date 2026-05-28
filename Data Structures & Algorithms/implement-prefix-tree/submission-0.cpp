class PrefixTree {
private:
    struct TreeNode {
        char val;
        bool endOfWord;
        vector<TreeNode*> children;

        TreeNode() : val(), endOfWord(false), children(26, nullptr) {}
        TreeNode(char c) : val(c), endOfWord(false), children(26, nullptr) {}
    };
public:
    TreeNode* root;
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* traverse = root;

        for (char c : word) {
            TreeNode* nextChild = traverse->children[c - 'a'];
            if (!nextChild) {
                nextChild = new TreeNode(c);
                traverse->children[c - 'a'] = nextChild;
            } 
            traverse = nextChild;
        }

        traverse->endOfWord = true;
    }
    
    bool search(string word) {
        TreeNode* traverse = root;

        for (char c : word) {
            TreeNode* nextChild = traverse->children[c - 'a'];
            if (!nextChild) return false;
            else traverse = nextChild;
        }

        return traverse->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* traverse = root;

        for (char c : prefix) {
            TreeNode* nextChild = traverse->children[c - 'a'];
            if (!nextChild) return false;
            else traverse = nextChild;
        }

        return true;
    }
};
