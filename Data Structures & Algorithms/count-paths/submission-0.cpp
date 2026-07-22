class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(dp, m - 1, n - 1);
    }

    int dfs(vector<vector<int>>& dp, int row, int col) {
        if (row < 0 || col < 0) return 0;
        if (row == 0 && col == 0) return 1;

        if (dp[row][col] > 0) return dp[row][col];

        dp[row][col] = dfs(dp, row - 1, col) + dfs(dp, row, col - 1);
        return dp[row][col];
    }
};
