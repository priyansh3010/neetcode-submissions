class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ROWS;
    int COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size(); COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c, visited);
            if (board[ROWS - 1][c] == 'O') dfs(board, ROWS - 1, c, visited);
        }

        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0, visited);
            if (board[r][COLS - 1] == 'O') dfs(board, r, COLS - 1, visited);
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        for (auto const& direction : directions) {
            int nr = r + direction[0];
            int nc = c + direction[1];
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && 
                board[nr][nc] == 'O' && !visited[nr][nc]) {
                    dfs(board, nr, nc, visited);
            }
        }
    }
};
