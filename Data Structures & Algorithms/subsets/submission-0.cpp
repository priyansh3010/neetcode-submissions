class Solution {
    vector<vector<int>> result;
public:
    void generateSubsets(vector<int>& nums, int i, vector<int>& temp) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        generateSubsets(nums, i + 1, temp);
        temp.pop_back();
        generateSubsets(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        
        generateSubsets(nums, 0, temp);
        return result;
    }
};
