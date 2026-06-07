class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ROWS;
    int COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size(); COLS = board[0].size();

        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[ROWS - 1][c] == 'O') dfs(board, ROWS - 1, c);
        }

        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][COLS - 1] == 'O') dfs(board, r, COLS - 1);
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        board[r][c] = 'Y';
        for (auto const& direction : directions) {
            int nr = r + direction[0];
            int nc = c + direction[1];
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && 
                board[nr][nc] == 'O') {
                    dfs(board, nr, nc);
            }
        }
    }
};
