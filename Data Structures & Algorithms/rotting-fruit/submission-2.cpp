class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int numOfOranges = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                } 
                if (grid[i][j] == 1) numOfOranges++;
            }
        }

        if (numOfOranges == 0) return 0;

        int count = -1;
        while (!q.empty()) {
            int size = q.size();

            for (int _ = 0; _ < size; _++) {
                pair<int, int> next = q.front(); q.pop();

                int i = next.first, j = next.second;

                if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                    q.push({i - 1, j}); 
                    visited[i - 1][j] = true;
                }
                if (i + 1 < grid.size() && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                    q.push({i + 1, j}); 
                    visited[i + 1][j] = true;
                }
                if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                    q.push({i, j - 1});
                    visited[i][j - 1] = true;
                }
                if (j + 1 < grid[i].size() && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                    q.push({i, j + 1});
                    visited[i][j + 1] = true;
                } 

                if (grid[i][j] == 1) numOfOranges--;
            }
            
            count++;
        }

        return numOfOranges == 0 ? count : -1;
    }
};
