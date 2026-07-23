class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        return dfs(dp, prices, 0, false);
    }

    int dfs(vector<vector<int>>& dp, vector<int>& prices, int i, bool holding) {
        if (i >= prices.size()) return 0;
        if (dp[i][holding] >= 0) return dp[i][holding];

        int doNothing = dfs(dp, prices, i + 1, holding);
        int action;

        if (holding) action = prices[i] + dfs(dp, prices, i + 2, !holding);
        else action = -prices[i] + dfs(dp, prices, i + 1, !holding);

        return dp[i][holding] = max({0, doNothing, action});
    } 
};
