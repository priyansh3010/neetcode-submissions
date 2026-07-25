class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // padding either sides of the array for easier calculations
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return dfs(dp, nums, 0, nums.size() - 1);
    }

    int dfs(vector<vector<int>>& dp, vector<int>& nums, int l, int r) {
        if (l + 1 == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int best = dp[l][r];
        for (int i = l + 1; i < r; i++) {
            int coins = nums[l] * nums[i] * nums[r]
                      + dfs(dp, nums, l, i)
                      + dfs(dp, nums, i, r);

            best = max(best, coins);
        }

        return dp[l][r] = best;
    }
};
