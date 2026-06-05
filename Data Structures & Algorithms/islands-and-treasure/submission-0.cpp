class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i - 1, j});
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                    visited[i][j] = true;
                }
            }
        }

        int dist = 1;
        while (!q.empty()) {
            int currSize = q.size();
            for (int _ = 0; _ < currSize; _++) {
                pair<int, int> next = q.front(); q.pop();
                int i = next.first, j = next.second;

                if (i < 0 || j < 0 || i == grid.size() || j == grid[i].size()) continue;
                if (visited[i][j] || grid[i][j] == -1) continue;

                q.push({i - 1, j});
                q.push({i + 1, j});
                q.push({i, j + 1});
                q.push({i, j - 1});
                visited[i][j] = true;
                
                grid[i][j] = dist;
            }
            dist++;
        }
    }
};
