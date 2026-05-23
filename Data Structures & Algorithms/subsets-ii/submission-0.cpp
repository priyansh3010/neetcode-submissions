class Solution {
    vector<vector<int>> result;
    vector<int> curr;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        generate(nums, 0);
        return result;
    }

    void generate(vector<int>& nums, int index) {
        result.push_back(curr);

        for (int j = index; j < nums.size(); j++) {
            if (j > index && nums[j] == nums[j - 1]) continue;

            curr.push_back(nums[j]);
            generate(nums, j + 1);
            curr.pop_back();
        }
    }
};
