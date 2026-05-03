class Solution {
    unordered_set<int> explored;
    int currArea;
    int maxArea;
    int rowCount;
    int colCount;
public:
    void countArea(vector<vector<int>>& grid, int row, int col) {
        if (row == -1 || col == -1 || row == rowCount || col == colCount) return;
        if (grid[row][col] == 0) return;
        if (explored.find(row * colCount + col) != explored.end()) return;

        explored.insert(row * colCount + col);
        currArea++;
        countArea(grid, row, col + 1);
        countArea(grid, row, col - 1);
        countArea(grid, row + 1, col);
        countArea(grid, row - 1, col);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        currArea = 0;
        maxArea = 0;
        rowCount = grid.size();
        colCount = grid[0].size();

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                if (grid[i][j] == 0) continue;
                if (explored.find(i * colCount + j) != explored.end()) continue;

                currArea = 0;
                countArea(grid, i, j);
                maxArea = max(maxArea, currArea);
            }
        }

        return maxArea;
    }
};
