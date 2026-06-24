class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, CustomMinHeap> minHeap;

        int n = grid.size();
        minHeap.push({grid[0][0], 0, 0});
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(n, vector(n, false));
        while (!minHeap.empty()) {
            auto curr = minHeap.top(); minHeap.pop();
            int r = curr[1], c = curr[2];
            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == n - 1 && c == n - 1) return curr[0];

            for (auto const& direction : directions) {
                int nr = r + direction[0], nc = c + direction[1];
                if (nr < 0 || nc < 0 || nr == n || nc == n) continue;
                if (visited[nr][nc]) continue;

                minHeap.push({max(curr[0], grid[nr][nc]), nr, nc});
            }
        }

        return -1;
    }

    struct CustomMinHeap {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }
    };
};
