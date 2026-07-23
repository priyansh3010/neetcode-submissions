class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount, -1));

        return dfs(dp, coins, amount, 0, 0);
    }

    int dfs(vector<vector<int>>& dp, vector<int>& coins, int& target, int curr, int i) {
        if (i >= coins.size()) return 0;
        if (curr >= target) return curr == target ? 1 : 0;

        if (dp[i][curr] >= 0) return dp[i][curr]; // this optimization is not working

        return dp[i][curr] = dfs(dp, coins, target, curr, i + 1) +
                             dfs(dp, coins, target, curr + coins[i], i);
    }
};
