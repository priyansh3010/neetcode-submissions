class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());

        int maxAmount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) dp[i] = nums[i];
            else if (i == 1) dp[i] = max(dp[i - 1], nums[i]);
            else dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            maxAmount = max(maxAmount, dp[i]);
        }

        return maxAmount;
    }
};
