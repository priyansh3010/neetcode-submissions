class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size(), unordered_map<int, int>());

        return dfs(dp, nums, target, 0, 0);
    }

    int dfs(vector<unordered_map<int, int>>& dp, vector<int>& nums, int& target, int curr, int i) {
        if (i >= nums.size()) return curr == target ? 1 : 0;

        if (dp[i].find(curr) != dp[i].end()) return dp[i][curr];

        dp[i][curr] = dfs(dp, nums, target, curr + nums[i], i + 1) +
                      dfs(dp, nums, target, curr - nums[i], i + 1);
        
        return dp[i][curr]; 
    }
};
