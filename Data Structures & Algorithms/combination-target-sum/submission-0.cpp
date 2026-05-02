class Solution {
    vector<vector<int>> result;
public:
    void generateAnswers(vector<int>& nums, vector<int>& currCombo, int& target, int& currSum, int start) {
        if (target <= currSum) {
            if (target == currSum) result.push_back(currCombo);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            currSum += nums[i];
            currCombo.push_back(nums[i]);
            generateAnswers(nums, currCombo, target, currSum, i);
            currSum -= nums[i];
            currCombo.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> currCombo;
        int currSum = 0;

        generateAnswers(nums, currCombo, target, currSum, 0);
        return result;
    }
};
