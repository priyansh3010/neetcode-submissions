class Solution {
    unordered_set<int> explored;
    int rowCount;
    int colCount;
public:
    void exploreIsland(vector<vector<char>>& grid, int row, int col) {
        if (row == -1 || col == -1 || row == rowCount || col == colCount || grid[row][col] == '0') return;
        if (explored.find(row * colCount + col) != explored.end()) return;

        explored.insert(row * colCount + col);
        exploreIsland(grid, row, col + 1);
        exploreIsland(grid, row, col - 1);
        exploreIsland(grid, row - 1, col);
        exploreIsland(grid, row + 1, col);
    }

    int numIslands(vector<vector<char>>& grid) {
        rowCount = grid.size();
        colCount = grid[0].size();

        int islandCount = 0;
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                if (grid[i][j] == '0') continue;
                if (explored.find(i * colCount + j) == explored.end()) {
                    cout << i << " " << j << endl;
                    exploreIsland(grid, i, j);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
