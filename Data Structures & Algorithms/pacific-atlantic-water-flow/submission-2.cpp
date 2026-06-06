class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++) {
            dfs(heights, 0, c, pac);
            dfs(heights, ROWS - 1, c, atl);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, r, 0, pac);
            dfs(heights, r, COLS - 1, atl);
        }

        vector<vector<int>> result;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (pac[i][j] && atl[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;
        for (auto const& direction : directions) {
            int nr = r + direction[0], nc = c + direction[1];
            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[nr].size() &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
                dfs(heights, nr, nc, ocean);
        }
    }
};
