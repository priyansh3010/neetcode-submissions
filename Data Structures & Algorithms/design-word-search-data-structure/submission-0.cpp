class WordDictionary {
private:
    struct TreeNode {
        bool endOfWord;
        vector<TreeNode*> children;

        TreeNode() : endOfWord(false), children(26, nullptr) {}
    };
public:
    TreeNode* root;
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* traverse = root;

        for (char c : word) {
            TreeNode* nextChild = traverse->children[c - 'a'];
            if (!nextChild) {
                nextChild = new TreeNode();
                traverse->children[c - 'a'] = nextChild;
            }
            traverse = nextChild;
        }

        traverse->endOfWord = true;
    }
    
    bool search(string word, int index = 0, TreeNode* currNode = nullptr) {
        TreeNode* traverse = currNode ? currNode : root;

        for (int i = index; i < word.size(); i++) {
            char c = word[i];

            if (c != '.') {
                TreeNode* nextChild = traverse->children[c - 'a'];
                if (!nextChild) return false;
                traverse = nextChild;
            }
            else {
                for (auto child : traverse->children) {
                    if (!child) continue;
                    if (search(word, i + 1, child)) return true;
                }
                return false;
            }
        }

        return traverse->endOfWord;
    }
};
