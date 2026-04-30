class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> rowTracker(9), colTracker(9);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    if (rowTracker[val]) return false;
                    rowTracker[val] = 1;
                }
                if (board[j][i] != '.') {
                    int val = board[j][i] - '1';
                    if (colTracker[val]) return false;
                    colTracker[val] = 1;
                }
            }
        }

        vector<vector<unordered_set<char>>> tracker(3, vector<unordered_set<char>>(3));
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') continue;
                char val = board[row][col];
                int i = row / 3, j = col / 3;
                if (tracker[i][j].count(val)) return false;
                tracker[i][j].insert(val);
            }
        }

        return true;
    }
};