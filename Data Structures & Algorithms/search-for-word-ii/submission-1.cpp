class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;

    TrieNode() : children(26, nullptr), isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) return;
        if (board[r][c] == '.') return;
        if (!node->children[board[r][c] - 'a']) return;

        node = node->children[board[r][c] - 'a'];
        word += board[r][c];
        if (node->isWord) {
            res.insert(word);
        }

        char currChar = board[r][c];
        board[r][c] = '.';
        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);
        board[r][c] = currChar;
    }
};