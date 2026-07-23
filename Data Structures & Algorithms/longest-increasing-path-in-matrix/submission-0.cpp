class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<bool>> visiting(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int maxLength = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                maxLength = max(maxLength, dfs(dp, matrix, visiting, i, j, -1));
            }
        }
        return maxLength;
    }

    int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, vector<vector<bool>>& visiting, int i, int j, int prev) {
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[i].size()) return 0;
        if (visiting[i][j]) return 0;
        if (matrix[i][j] <= prev) return 0;

        if (dp[i][j] != -1) return dp[i][j] + 1;

        visiting[i][j] = true;
        dp[i][j] = max({
            dfs(dp, matrix, visiting, i + 1, j, matrix[i][j]),
            dfs(dp, matrix, visiting, i - 1, j, matrix[i][j]),
            dfs(dp, matrix, visiting, i, j + 1, matrix[i][j]),
            dfs(dp, matrix, visiting, i, j - 1, matrix[i][j])
        });
        visiting[i][j] = false;

        return dp[i][j] + 1;
    }
};
