class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 == 1) return false;

        int goal = total / 2;
        unordered_set<int> dp;

        dp.insert(0);
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> newDP;
            for (int t : dp) {
                newDP.insert(t + nums[i]);
                newDP.insert(t);
            }
            dp = newDP;
        }

        return dp.find(goal) != dp.end() ? true : false;
    }
};